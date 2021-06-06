#include<iostream>
#include<vector>
#include<algorithm>
//����⻹�Ǻ�����ģ���Ҫ�Ա��������ظ���Ԫ��ȥ�أ�
//����һ�־����ȥ���߼�������������ض�����ݹ鲻���أ�491���ȥ���߼���һ����
//����Ҫע�⣺���ȥ��ֻ���ÿһ����������Ԫ�أ�ÿһ������������Ԫ�ز�������ͬ�ģ�
//����ݹ��ʱ���������Ԫ�ؿ������ظ��ģ�
//����ݹ�������ǵ�ǰret_line�е�Ԫ�أ���������ǽ���Щret_line�Ž�ret��Ҫ����һ��Ԫ�ص�ret_line�ʹ��ˣ���
//֮����Ҫ��һ��bool������ȥ������Ϊ��Ҫ��¼�����е�ǰ��Ԫ��֮ǰ�ǲ����б����������
//���������Ѿ���ǰ�ź����ˣ��ظ���Ԫ�ض���һ������ֻ��Ҫ��鵱ǰԪ�ص���һ���Ƿ񱻺�������������ˣ�
using namespace std;
class Solution {
public:
	vector<int> cand;
	int m_target;
	vector<vector<int>> ret;
	vector<int> ret_line;
	vector<bool> isUse;//����߼��ǣ�ͬ���������Ҫ����ظ����֣���true�����ݹ�ʱ������Ҫ����ظ�������false��
	int cur_sum;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		cand = candidates;
		sort(cand.begin(), cand.end());//����������Ҫ��������
		m_target = target;
		vector<bool> use(cand.size(), true);
		isUse = use;
		backtracing(0);
		return ret;
	}
	void backtracing(int cur) {
		if (cur_sum == m_target)
		{
			ret.push_back(ret_line);
			return;
		}
		if (cur_sum > m_target)
		{
			return;
		}
		for (int i = cur; i < cand.size(); i++) {
			//������ζ�ű���ʹ�����ظ������֣�Ӧ������
			if (i > 0 && isUse[i - 1] == true && cand[i] == cand[i - 1]) continue;
			ret_line.push_back(cand[i]);
			cur_sum += cand[i];
			isUse[i] = false;//�ݹ�֮ǰ��isUse[i]�ó�false��Ϊ��ȷ������������ʱ�򣬲�����Ϊʹ�ù���ͬ���ֶ�����
			backtracing(i + 1);
			isUse[i] = true;//�ݹ鷵��֮���ٰ�isUse[i]�û�true����ʱ�����ʱ��������ظ���Ԫ�ؾͻ�������Ԫ����
			cur++;
			cur_sum -= cand[i];
			ret_line.pop_back();
		}
	}
};
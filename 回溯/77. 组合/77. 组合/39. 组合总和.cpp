#include<iostream>
#include<vector>
//����ǰ��������������Ҳ�Ƚ�����һ��д������ע��һ�µ���ʲôʱ��÷��أ���ǰ�治һ���ĵط���
//ע�����������Ŀ��ƣ�curֵ��
//�Ӽ��ٵݹ麯�����νǶ���˵�����������Խ�ʡÿ�εݹ鴫��һ�����飬���ܻ����һЩ
using namespace std;
class Solution {
public:
	vector<int> cand;
	int m_target;
	vector<vector<int>> ret;
	vector<int> ret_line;
	int cur_sum;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		cand = candidates;
		m_target = target;
		backtracking(0);
		return ret;
	}
	void backtracking(int cur) {
		if (cur_sum > m_target)
		{
			return;
		}
		if (cur_sum == m_target)
		{
			ret.push_back(ret_line);
			return;
		}
		for (int i = cur; i < cand.size(); i++) {
			ret_line.push_back(cand[i]);
			cur_sum += cand[i];
			backtracking(cur);
			cur++;//ÿ��ѭ���������������curֵ��ʼ��ÿ�η��ص�ʱ��ŵ���curֵ
			//�������Ա�֤��һ��Ѱ�ҵ�ֵ�Ǳȵ�ǰֵ��ģ������ظ�
			cur_sum -= cand[i];
			ret_line.pop_back();
		}
	}
};
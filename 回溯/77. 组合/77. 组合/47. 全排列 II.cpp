#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
//������ȫ���е�Ψһ���������Ҫ�Ѻ������ʱ�ظ���Ԫ���ų���,��40��ľ���ȥ�ط���һ��
//֮����Ҫ��һ��bool������ȥ������Ϊ��Ҫ��¼�����е�ǰ��Ԫ��֮ǰ�ǲ����б����������
//���������Ѿ���ǰ�ź����ˣ��ظ���Ԫ�ض���һ������ֻ��Ҫ��鵱ǰԪ�ص���һ���Ƿ񱻺�������������ˣ�
using namespace std; 
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> ret_line;
	unordered_map<int, bool> mp;//�����ϣ���key�������±꣬����Ԫ��ֵ��
	vector<int> m_nums;
	vector<bool> isDup;//����Ƿ�����ظ����;����ȥ���߼�һ����ֻ�������ظ������������ظ���
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		m_nums = nums;
		sort(m_nums.begin(), m_nums.end());
		vector<bool> dup(m_nums.size(), false);
		isDup = dup;
		backtracking();
		return ret;
	}
	void backtracking(void) {//ʼ��Ҳû��������õ�cur��������Ȼ���Բ��ô���
		int nums_s = m_nums.size();
		if (ret_line.size() >= nums_s)
		{
			ret.push_back(ret_line);
			return;
		}
		for (int i = 0; i < nums_s; i++) {
			if (mp[i] || (i > 0 && m_nums[i - 1] == m_nums[i] && isDup[i - 1])) continue;//�����������ݹ����Ԫ�ػ�����������Ԫ�أ�������
			ret_line.push_back(m_nums[i]);
			mp[i] = true;//��Ǻ�����������������������Ԫ��
			isDup[i] = false;
			backtracking();
			isDup[i] = true;
			mp[i] = false;
			ret_line.pop_back();
		}
	}
};
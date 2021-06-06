#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
//ȫ�������⣬��ʵ˼·����������ͬС�죬�������ͻᷢ��û��Ҫ����cur����ǰ�����Ľڵ㣩
//��Ϊÿ�α������Ǵ������һ��Ԫ�ؿ�ʼ�����������������ݹ����Ԫ�ػ�����������Ԫ�أ�������
//ʼ��Ҳû��������õ�cur��������Ȼ���Բ��ô���
using namespace std;
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> ret_line;
	unordered_map<int, bool> mp;//�����˹�ϣ��carl�ñ�־������Ϊ�ݹ麯�����ݲ�������ʵһ��
	vector<int> m_nums;
	vector<vector<int>> permute(vector<int>& nums) {
		m_nums = nums;
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
			if (mp[m_nums[i]]) continue;//�����������ݹ����Ԫ�ػ�����������Ԫ�أ�������
			ret_line.push_back(m_nums[i]);
			mp[m_nums[i]] = true;//��Ǻ�����������������������Ԫ��
			backtracking();
			mp[m_nums[i]] = false;
			ret_line.pop_back();
		}
	}
};
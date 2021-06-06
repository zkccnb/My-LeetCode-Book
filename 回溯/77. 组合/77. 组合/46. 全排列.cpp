#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
//全排列问题，其实思路和组合问题大同小异，做到最后就会发现没必要传递cur（当前遍历的节点）
//因为每次遍历都是从数组第一个元素开始遍历，如果遇到纵向递归过的元素或横向遍历到的元素，则跳过
//始终也没用上组合用的cur，所以自然可以不用传递
using namespace std;
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> ret_line;
	unordered_map<int, bool> mp;//我用了哈希表，carl用标志数组作为递归函数传递参数，其实一样
	vector<int> m_nums;
	vector<vector<int>> permute(vector<int>& nums) {
		m_nums = nums;
		backtracking();
		return ret;
	}
	void backtracking(void) {//始终也没用上组合用的cur，所以自然可以不用传递
		int nums_s = m_nums.size();
		if (ret_line.size() >= nums_s)
		{
			ret.push_back(ret_line);
			return;
		}
		for (int i = 0; i < nums_s; i++) {
			if (mp[m_nums[i]]) continue;//如果遇到纵向递归过的元素或横向遍历到的元素，则跳过
			ret_line.push_back(m_nums[i]);
			mp[m_nums[i]] = true;//标记横向和纵向两个方向遍历到的元素
			backtracking();
			mp[m_nums[i]] = false;
			ret_line.pop_back();
		}
	}
};
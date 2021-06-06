#include<iostream>
#include<vector>
//做了前面三道题后，这道题也比较容易一次写出来，注意一下到底什么时候该返回（和前面不一样的地方）
//注意横向遍历起点的控制（cur值）
//从减少递归函数传参角度来说，这样做可以节省每次递归传入一个数组，可能会更快一些
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
			cur++;//每次循环（横向遍历）从cur值开始，每次返回的时候才递增cur值
			//这样可以保证下一次寻找的值是比当前值大的，不会重复
			cur_sum -= cand[i];
			ret_line.pop_back();
		}
	}
};
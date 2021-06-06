#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
//这个题和全排列的唯一区别就是需要把横向遍历时重复的元素排除掉,和40题的经典去重方法一样
//之所以要用一个bool型数组去重是因为需要记录数组中当前的元素之前是不是有被横向遍历过
//由于数组已经提前排好序了，重复的元素都在一起，所以只需要检查当前元素的上一个是否被横向遍历过就行了！
using namespace std; 
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> ret_line;
	unordered_map<int, bool> mp;//这个哈希表的key是数组下标，不是元素值！
	vector<int> m_nums;
	vector<bool> isDup;//检查是否横向重复（和经典的去重逻辑一样，只检查横向重复，忽略纵向重复）
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		m_nums = nums;
		sort(m_nums.begin(), m_nums.end());
		vector<bool> dup(m_nums.size(), false);
		isDup = dup;
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
			if (mp[i] || (i > 0 && m_nums[i - 1] == m_nums[i] && isDup[i - 1])) continue;//如果遇到纵向递归过的元素或横向遍历到的元素，则跳过
			ret_line.push_back(m_nums[i]);
			mp[i] = true;//标记横向和纵向两个方向遍历到的元素
			isDup[i] = false;
			backtracking();
			isDup[i] = true;
			mp[i] = false;
			ret_line.pop_back();
		}
	}
};
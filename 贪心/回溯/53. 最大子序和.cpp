#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
//贪心在于：每次先计算当前和，如果当前和小于0，立刻放弃此子序列。
//最终取到最大的当前和就是结果
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ret = INT_MIN, cur_sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			cur_sum += nums[i];
			ret = max(cur_sum, ret);
			if (cur_sum < 0)
			{
				cur_sum = 0;
			}
		}
		return ret;
	}
};
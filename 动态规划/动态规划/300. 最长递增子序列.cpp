#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//这个题最巧妙的地方在于其递推公式的含义：dp[2]
//这个题dp[i]数组的含义很重要：下标i及i之前的所有元素，最长递增子序列中所含元素个数
//递推公式也比较抽象。。
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int nums_s = nums.size();
		int max_length = 0;
		vector<int> dp(nums_s, 1);
		for (int i = 0; i < nums_s; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
			max_length = max_length > dp[i] ? max_length : dp[i];
		}
		return max_length;
	}
};
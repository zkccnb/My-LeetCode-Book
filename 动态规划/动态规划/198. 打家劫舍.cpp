#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//小偷系列！这个递推公式还是很难想到的，dp[i]的意义是：从第0家打劫到第i家，最多可以赚多少钱？
class Solution {
public:
	int rob(vector<int>& nums) {
		size_t nums_s = nums.size();
		vector<int> dp(nums_s, 0);
		dp[0] = nums[0];//初始化，很显然应该这样
		for (int i = 1; i < nums_s; i++) {
			//注意对边界情况的处理！
			if ((i - 2) >= 0) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
			else dp[i] = max(nums[i], dp[i - 1]);
		}
		return dp[nums_s - 1];
	}
};

//213. 打家劫舍Ⅱ，各房屋间是个环，收尾相接！所以只要像下面这样考虑这两种情况就行了（转换为打家劫舍1），rob1的程序就和上面的一样了
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		return max(rob1({ nums.begin() + 1,nums.end() }), rob1({ nums.begin(),nums.end() - 1 }));
	}
	int rob1(vector<int> nums) {
		int nums_s = nums.size();
		vector<int> dp(nums_s, 0);
		dp[0] = nums[0];
		for (int i = 1; i < nums_s; i++) {
			if (i >= 2) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
			else dp[i] = max(nums[i], dp[i - 1]);
		}
		return dp[nums_s - 1];
	}
};
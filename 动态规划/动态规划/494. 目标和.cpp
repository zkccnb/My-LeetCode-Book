#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//01背包问题解法：(滚动数组法）
//dp[j]数组含义：背包容量为j时，可装的最大价值为dp[j]
//dp数组初始化：全零
//递推公式：dp[j]=max(dp[j], dp[j-w[i]]+v[i])，while i=0-num（num个物品）
//（递推公式怎么想呢？你就试着想想dp[j]可以根据dp数组的哪几项推出来，把这几项的递推表达式单独列出来，再这几项的推出表达式满足什么关系？）
//遍历方式：先物品再容量，容量从后向前，每个物品遍历到背包容量小于当前物品重量为止

//能用01背包解决的问题都是要转换成“子数组和问题”或“子数组和排列组合问题”
//这道题需要我们转化成求有多少个子数组和等于(sum + target) / 2  的子数组和的组合问题
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for (auto num : nums) sum += num;
		if ((sum + target) % 2 || target > sum) return 0;
		int packsize = (sum + target) / 2;//背包最大大小，也是dp数组的大小

		vector<int> dp(packsize + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = packsize; j >= nums[i]; j--) {
				dp[j] += dp[j - nums[i]];//子数组和的组合问题的递推公式
			}
		}
		return dp[packsize];
	}
};
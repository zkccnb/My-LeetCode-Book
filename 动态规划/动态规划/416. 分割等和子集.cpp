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

//这个题可以用回溯枚举所有情况，但是会超时。。一种做法是把它抽象成01背包，套用公式做（不告诉你可以这么做你怎么可能想得到啊。。。）
//01背包，是指每个物品只能拿一次的背包问题。（完全背包每个物品可以拿无数次）
//如何转换成01背包呢？
//nums数组即是v数组又是w数组，目的也是取当前背包容量的最大价值，当背包容量为target时，如果此时的最大value也为target，说明找到了一个合理的分割！
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int target = 0;
		for (int i = 0; i < nums.size(); i++) target += nums[i];
		if (target % 2) return false;
		target /= 2;//分割等和，其实就是找找看有没有一组子集，其和等于nums数组总和的一半，这个值也作为背包的最大容量
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = target; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		return dp[target] == target;
	}
};
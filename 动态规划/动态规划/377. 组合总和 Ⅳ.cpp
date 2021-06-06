#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//完全背包问题解法：(滚动数组法）
//dp[j]数组含义：背包容量为j时，可装的最大价值为dp[j]
//dp数组初始化：全零
//递推公式：dp[j]=max(dp[j], dp[j-w[i]]+v[i])，while i=0-num（num个物品）
//（递推公式怎么想呢？你就试着想想dp[j]可以根据dp数组的哪几项推出来，把这几项的递推表达式单独列出来，再这几项的推出表达式满足什么关系？）
//遍历方式：先物品再容量，容量从前向后

//这题明显可以等效成一个“完全背包排列问题”
//递推公式如下，初始化dp[0]=1,遍历顺序：先容量后物品，容量从前向后
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned long> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < target + 1; i++) {//容量
			for (int j = 0; j < nums.size(); j++) {//物品
				if (i - nums[j] >= 0) dp[i] += dp[i - nums[j]];//排列问题的时候要注意保护边界
			}
		}
		return dp[target];
	}
};
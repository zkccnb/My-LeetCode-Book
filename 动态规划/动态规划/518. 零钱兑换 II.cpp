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

//这题明显可以等效成一个“完全背包组合问题”
//递推公式如下，初始化dp[0]=1,遍历顺序：先物品后容量，容量从前向后
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); i++) {//物品
			for (int j = coins[i]; j < amount + 1; j++) {//容量
				dp[j] += dp[j - coins[i]];//背包组合的递归公式
			}
		}
		return dp[amount];
	}
};
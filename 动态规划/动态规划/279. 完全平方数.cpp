#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//完全背包问题解法：(滚动数组法）
//dp[j]数组含义：背包容量为j时，可装的最大价值为dp[j]
//dp数组初始化：全零
//递推公式：dp[j]=max(dp[j], dp[j-w[i]]+v[i])，while i=0-num（num个物品），递推公式本身和01背包一样，就是容量遍历顺序是从前向后（01背包的容量遍历顺序是从后向前）
//（递推公式怎么想呢？你就试着想想dp[j]可以根据dp数组的哪几项推出来，把这几项的递推表达式单独列出来，再这几项的推出表达式满足什么关系？）
//遍历方式：先物品再容量（其实对于纯背包完全背包问题均可！），容量从前向后

//这题明显可以等效成一个“单纯完全背包问题”
//递推公式如下，初始化dp[0]=0,遍历顺序：先物品再容量（其实对于纯背包完全背包问题均可！），容量从前向后
class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		int nums_i = 0;
		for (int j = 0; j < n + 1; j++) {
			nums_i = 0;
			for (int i = 1; i*i <= n; i++) {
				nums_i = i * i;
				if (j - nums_i >= 0) dp[j] = min(dp[j], dp[j - nums_i] + 1);
			}
		}
		return dp[n];
	}
};
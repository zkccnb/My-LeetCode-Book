#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//dp[i][j]含义：二维数组，代表走到坐标(i,j)所有可能的路径数目
//递推：dp[i][j]=dp[i-1][j] + dp[i][j-1]
//初值设置：dp[.][0]=dp[0][.]=1
//彻底搞懂了fibnacci系列问题是如何动规的之后，这道题其实很好想到，只不过dp数组的维度变成二维了
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) dp[i][0] = 1;
		for (int i = 0; i < n; i++) dp[0][i] = 1;
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};
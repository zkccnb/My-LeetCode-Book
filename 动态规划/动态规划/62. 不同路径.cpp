#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//dp[i][j]���壺��ά���飬�����ߵ�����(i,j)���п��ܵ�·����Ŀ
//���ƣ�dp[i][j]=dp[i-1][j] + dp[i][j-1]
//��ֵ���ã�dp[.][0]=dp[0][.]=1
//���׸㶮��fibnacciϵ����������ζ����֮���������ʵ�ܺ��뵽��ֻ����dp�����ά�ȱ�ɶ�ά��
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
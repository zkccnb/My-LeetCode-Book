#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//wc，这题的递归公式。。完全无法想到啊！背一下吧，这题还是挺有意思的
//递归也可以是一个带求和的复杂公式
class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 1; i < n + 1; i++) {
			for (int j = 0; j < i; j++) {
				dp[i] += dp[j] * dp[i - j - 1];
			}
		}
		return dp[n];
	}
};
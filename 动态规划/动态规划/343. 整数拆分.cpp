#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//这题重点是dp数组的含义啊，你对动态规划的精髓还得加深理解啊。。。
//感觉动态规划就是小学玩找规律游戏一样。。
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[2] = 1;
		for (int i = 3; i < n + 1; i++) {
			for (int j = 1; j < i - 1; j++) {
				dp[i] = max(dp[i], max(j*(i - j), j*dp[i - j]));
				//这显然不对啊大哥。。别忘了这是两层循环啊。。要比较所有可能的加法可能啊。。你这样只是把最后一个加法组合当成结果了啊
				//dp[i] = max(j*(i - j), j*dp[i - j]);
			}
		}
		for (int i = 0; i < n + 1; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;
		return dp[n];
	}
};
int main() {
	int ret = Solution().integerBreak(10);
	cout << ret << endl;
}
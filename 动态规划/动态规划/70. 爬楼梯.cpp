#include<iostream>
#include<vector>
using namespace std;
//这个关键是要想到递推公式就是斐波那契的递推。。。第一次想确实不容易想到。。
//上第i层楼梯有多少种方法呢？可以拆分为：
//上i-1层+上1层
//上i-2层+上2层
//所以：dp[i] = dp[i-1] + dp[i-2]（因为一次只能上一层或者两层，所以放心吧，一定是这样的！）

//换一种角度，此题也可以看成一个完全背包排列问题！（物品2个，重量/价值 分别是1和2；背包容量为n）
//class Solution {
//public:
//	int climbStairs(int n) {
//		int dp[2] = { 1,2 };//注意初值的设置
//		int next = 0;
//		if (n <= 2) return n;
//		for (int i = 2; i < n; i++) {
//			next = dp[0] + dp[1];
//			dp[0] = dp[1];
//			dp[1] = next;
//		}
//		return next;
//	}
//};

//换一种角度，此题也可以看成一个完全背包排列问题！（物品2个，重量/价值 分别是1和2；背包容量为n）
class Solution {
public:
	int climbStairs(int n) {
		int value[2] = { 1,2 };
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < 2; j++) {
				if (i - value[j]>=0) dp[i] += dp[i - value[j]];
			}
		}
		return dp[n];
	}
};
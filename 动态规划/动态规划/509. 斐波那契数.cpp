#include<iostream>
using namespace std;
//动态规划的经典入门题目，很简单；但要吸收思想：
//1. 确定dp数组的意义
//2. 确定递归式
//3. dp数组的初值
//4. 如何遍历？
//5. 试着推导、写写
class Solution {
public:
	int fib(int n) {
		if (n < 2) return n;
		int dp[2] = { 0,1 };//dp数组初值
		int next = 0;
		//for循环中的就是遍历得出dp数组的方法（这种方式避免了递归，一开始不太好想）
		for (int i = 2; i <= n; i++) {
			next = dp[0] + dp[1];//递归式
			dp[0] = dp[1];
			dp[1] = next;
		}
		return next;
	}
};
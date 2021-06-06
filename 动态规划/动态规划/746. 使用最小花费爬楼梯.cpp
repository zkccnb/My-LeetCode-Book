#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//dp[i]含义：爬到第i个楼梯的总花费
//递推：dp[i]=min(dp[i-1],dp[i-2])+cost[i]
//初值：见注释
//这个题在力扣上被很多人诟病，其题目描述非常糟糕。但动态规划的思想还是需要学习的
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int dp[2] = { cost[0],cost[1] };//初值
		for (int i = 2; i < cost.size(); i++) {
			int next = min(dp[0], dp[1]) + cost[i];
			dp[0] = dp[1];
			dp[1] = next;
		}
		//最后还要取dp数组后两个元素最小的作为最终结果，因为题目说可以选择从第一个或第二个阶梯开始走。。。最后这两个元素分别代表从第一个/第二个阶梯开始的结果
		return min(dp[0], dp[1]);
	}
};
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//01背包问题解法：(滚动数组法）
//dp[j]数组含义：背包容量为j时，可装的最大价值为dp[j]
//dp数组初始化：全零
//递推公式：dp[j]=max(dp[j], dp[j-w[i]]+v[i])，while i=0-num（num个物品）
//（递推公式怎么想呢？你就试着想想dp[j]可以根据dp数组的哪几项推出来，把这几项的递推表达式单独列出来，再这几项的推出表达式满足什么关系？）
//遍历方式：先物品再容量，容量从后向前，每个物品遍历到背包容量小于当前物品重量为止

//做了416.分割等和数组之后，会发现这个题和那个题十分类似，可以推导出来
//感觉这个题也有些贪心的意思，体现在最优解就是：把数组分成两个子数组，使二者的和最接近，再把二者的和相减即为最后一块石头最小的重量
class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		int target, total = 0;
		for (int i = 0; i < stones.size(); i++) total += stones[i];
		target = total / 2;
		//和416完全一样的转换成01背包
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < stones.size(); i++) {
			for (int j = target; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		return abs(total - 2 * dp[target]);//只不过返回的是两个 和相差最近的子数组 的和的差
	}
};
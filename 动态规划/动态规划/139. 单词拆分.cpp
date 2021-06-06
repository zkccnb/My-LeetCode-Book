#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//完全背包问题解法：(滚动数组法）
//dp[j]数组含义：背包容量为j时，可装的最大价值为dp[j]
//dp数组初始化：全零
//递推公式：dp[j]=max(dp[j], dp[j-w[i]]+v[i])，while i=0-num（num个物品），递推公式本身和01背包一样，就是容量遍历顺序是从前向后（01背包的容量遍历顺序是从后向前）
//（递推公式怎么想呢？你就试着想想dp[j]可以根据dp数组的哪几项推出来，把这几项的递推表达式单独列出来，再这几项的推出表达式满足什么关系？）
//遍历方式：先物品再容量（其实对于纯背包完全背包问题均可！），容量从前向后

//这题给我做麻了。。看起来很像完全背包，但是很难想到怎么把他转换到完全背包
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> word_set(wordDict.begin(), wordDict.end());
		size_t s_size = s.size();
		vector<bool> dp(s_size + 1, false);
		dp[0] = true;
		for (int i = 0; i < s_size + 1; i++) {
			for (int j = 0; j < i; j++) {
				string sub = s.substr(j, i - j);
				if (word_set.find(sub) != word_set.end() && dp[j]) { dp[i] = true; }
			}
		}
		return dp[s_size];
	}
};
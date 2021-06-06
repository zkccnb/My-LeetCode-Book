#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//和回文字串做法类似，dp[i][j]数组含义：i-j区间内最长的回文串有多长
//注意这道题的最长回文串可以不连续
//另外，动态数组版本比vector快了2.5倍，所以对于方便确定其长度且不需动态增加的数组最好使用动态数组或array
//vector版本
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         size_t s_s=s.size();
//         vector<vector<int>> dp(s_s,vector<int>(s_s,0));
//         for(int i=0;i<s_s;i++) dp[i][i]=1;
//         int ret=1;
//         for(int i=s_s-1;i>=0;i--){
//             for(int j=i+1;j<s_s;j++){
//                 if(s[i]==s[j]) {dp[i][j]=dp[i+1][j-1]+2;ret=max(ret,dp[i][j]);}
//                 else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
//             }
//         }
//         return ret;
//     }
// };
//堆区数组版本
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		size_t s_s = s.size();
		int** dp = new int*[s_s];
		for (int i = 0; i < s_s; i++) { dp[i] = new int[s_s](); dp[i][i] = 1; }
		int ret = 1;
		for (int i = s_s - 1; i >= 0; i--) {
			for (int j = i + 1; j < s_s; j++) {
				if (s[i] == s[j]) { dp[i][j] = dp[i + 1][j - 1] + 2; ret = max(ret, dp[i][j]); }
				else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		for (int i = 0; i < s_s; i++) delete[] dp[i];
		delete[] dp;
		return ret;
	}
};

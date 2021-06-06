#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//�ͻ����ִ��������ƣ�dp[i][j]���麬�壺i-j��������Ļ��Ĵ��ж೤
//ע������������Ĵ����Բ�����
//���⣬��̬����汾��vector����2.5�������Զ��ڷ���ȷ���䳤���Ҳ��趯̬���ӵ��������ʹ�ö�̬�����array
//vector�汾
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
//��������汾
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

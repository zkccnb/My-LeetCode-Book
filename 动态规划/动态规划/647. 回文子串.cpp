#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//这题的dp数组非常巧妙！dp[i][j]的含义是：区间i-j是否为回文串（若是为true，不是为false）
//最后统计一下二维数组中true的个数即可
class Solution {
public:
	int countSubstrings(string s) {
		size_t s_s = s.size();
		int ret = 0;
		vector<vector<bool>> dp(s_s, vector<bool>(s_s, false));
		//遍历的顺序需要注意，i必须从后向前才不会漏掉，j只需遍历比i大的就行了
		//（意味着二维数组的左下一半没有值）
		for (int i = s_s - 1; i >= 0; i--) {
			for (int j = i; j < s_s; j++) {
				if (s[i] == s[j])//如果i-j区间两端相同，则此区间有可能是回文串
				{
					//如果ji相邻或相同，则一定是回文串（aa或a）
					if (j - i <= 1) { dp[i][j] = true; ret++; }
					else
					{
						//如果两端字符相同且中间紧邻区间(i+1 - j-1)也是回文串，则一定是回文串
						//这个可能乍一看不太好理解。。（a bab a）
						if (dp[i + 1][j - 1] == true) { dp[i][j] = true; ret++; }
						else dp[i][j] = false;//两端一样但中间不是回文串（a bba a）
					}
				}
				else dp[i][j] = false;//如果区间i-j的两端不相同，则此区间一定不是回文串（aacb）
			}
		}
		return ret;
	}
};
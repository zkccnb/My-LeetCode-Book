#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//这个题最关键的是要注意，递推公式，仅当nums1[i - 1] == nums2[j - 1]才能使用，其他情况没有任何规律的！
//最后记录一个出现的最大值就行了，也就是说，二维的dp数组本题并没有全填满，只填了nums1[i - 1] == nums2[j - 1]部分
//最终记录了填入数据的最大值
class Solution {
public:
	int findLength(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
		int result = 0;
		for (int i = 1; i < nums1.size() + 1; i++) {
			for (int j = 1; j < nums2.size() + 1; j++) {
				if (nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				result = dp[i][j] > result ? dp[i][j] : result;
			}
		}
		return result;
	}
};
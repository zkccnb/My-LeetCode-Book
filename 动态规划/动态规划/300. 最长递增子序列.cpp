#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//�����������ĵط���������ƹ�ʽ�ĺ��壺dp[2]
//�����dp[i]����ĺ������Ҫ���±�i��i֮ǰ������Ԫ�أ������������������Ԫ�ظ���
//���ƹ�ʽҲ�Ƚϳ��󡣡�
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int nums_s = nums.size();
		int max_length = 0;
		vector<int> dp(nums_s, 1);
		for (int i = 0; i < nums_s; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
			max_length = max_length > dp[i] ? max_length : dp[i];
		}
		return max_length;
	}
};
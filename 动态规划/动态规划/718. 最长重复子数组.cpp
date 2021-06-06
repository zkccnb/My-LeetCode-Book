#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//�������ؼ�����Ҫע�⣬���ƹ�ʽ������nums1[i - 1] == nums2[j - 1]����ʹ�ã��������û���κι��ɵģ�
//����¼һ�����ֵ����ֵ�����ˣ�Ҳ����˵����ά��dp���鱾�Ⲣû��ȫ������ֻ����nums1[i - 1] == nums2[j - 1]����
//���ռ�¼���������ݵ����ֵ
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
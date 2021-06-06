#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//С͵ϵ�У�������ƹ�ʽ���Ǻ����뵽�ģ�dp[i]�������ǣ��ӵ�0�Ҵ�ٵ���i�ң�������׬����Ǯ��
class Solution {
public:
	int rob(vector<int>& nums) {
		size_t nums_s = nums.size();
		vector<int> dp(nums_s, 0);
		dp[0] = nums[0];//��ʼ��������ȻӦ������
		for (int i = 1; i < nums_s; i++) {
			//ע��Ա߽�����Ĵ���
			if ((i - 2) >= 0) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
			else dp[i] = max(nums[i], dp[i - 1]);
		}
		return dp[nums_s - 1];
	}
};

//213. ��ҽ���򣬸����ݼ��Ǹ�������β��ӣ�����ֻҪ����������������������������ˣ�ת��Ϊ��ҽ���1����rob1�ĳ���ͺ������һ����
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		return max(rob1({ nums.begin() + 1,nums.end() }), rob1({ nums.begin(),nums.end() - 1 }));
	}
	int rob1(vector<int> nums) {
		int nums_s = nums.size();
		vector<int> dp(nums_s, 0);
		dp[0] = nums[0];
		for (int i = 1; i < nums_s; i++) {
			if (i >= 2) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
			else dp[i] = max(nums[i], dp[i - 1]);
		}
		return dp[nums_s - 1];
	}
};
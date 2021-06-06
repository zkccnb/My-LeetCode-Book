#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
//̰�����ڣ�ÿ���ȼ��㵱ǰ�ͣ������ǰ��С��0�����̷����������С�
//����ȡ�����ĵ�ǰ�;��ǽ��
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ret = INT_MIN, cur_sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			cur_sum += nums[i];
			ret = max(cur_sum, ret);
			if (cur_sum < 0)
			{
				cur_sum = 0;
			}
		}
		return ret;
	}
};
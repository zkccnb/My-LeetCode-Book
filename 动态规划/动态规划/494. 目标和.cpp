#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//01��������ⷨ��(�������鷨��
//dp[j]���麬�壺��������Ϊjʱ����װ������ֵΪdp[j]
//dp�����ʼ����ȫ��
//���ƹ�ʽ��dp[j]=max(dp[j], dp[j-w[i]]+v[i])��while i=0-num��num����Ʒ��
//�����ƹ�ʽ��ô���أ������������dp[j]���Ը���dp������ļ����Ƴ��������⼸��ĵ��Ʊ��ʽ�����г��������⼸����Ƴ����ʽ����ʲô��ϵ����
//������ʽ������Ʒ�������������Ӻ���ǰ��ÿ����Ʒ��������������С�ڵ�ǰ��Ʒ����Ϊֹ

//����01������������ⶼ��Ҫת���ɡ�����������⡱�������������������⡱
//�������Ҫ����ת�������ж��ٸ�������͵���(sum + target) / 2  ��������͵��������
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for (auto num : nums) sum += num;
		if ((sum + target) % 2 || target > sum) return 0;
		int packsize = (sum + target) / 2;//��������С��Ҳ��dp����Ĵ�С

		vector<int> dp(packsize + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = packsize; j >= nums[i]; j--) {
				dp[j] += dp[j - nums[i]];//������͵��������ĵ��ƹ�ʽ
			}
		}
		return dp[packsize];
	}
};
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//��ȫ��������ⷨ��(�������鷨��
//dp[j]���麬�壺��������Ϊjʱ����װ������ֵΪdp[j]
//dp�����ʼ����ȫ��
//���ƹ�ʽ��dp[j]=max(dp[j], dp[j-w[i]]+v[i])��while i=0-num��num����Ʒ��
//�����ƹ�ʽ��ô���أ������������dp[j]���Ը���dp������ļ����Ƴ��������⼸��ĵ��Ʊ��ʽ�����г��������⼸����Ƴ����ʽ����ʲô��ϵ����
//������ʽ������Ʒ��������������ǰ���

//�������Կ��Ե�Ч��һ������ȫ�����������⡱
//���ƹ�ʽ���£���ʼ��dp[0]=1,����˳������������Ʒ��������ǰ���
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<unsigned long> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < target + 1; i++) {//����
			for (int j = 0; j < nums.size(); j++) {//��Ʒ
				if (i - nums[j] >= 0) dp[i] += dp[i - nums[j]];//���������ʱ��Ҫע�Ᵽ���߽�
			}
		}
		return dp[target];
	}
};
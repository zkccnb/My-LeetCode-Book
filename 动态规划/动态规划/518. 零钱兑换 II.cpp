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

//�������Կ��Ե�Ч��һ������ȫ����������⡱
//���ƹ�ʽ���£���ʼ��dp[0]=1,����˳������Ʒ��������������ǰ���
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); i++) {//��Ʒ
			for (int j = coins[i]; j < amount + 1; j++) {//����
				dp[j] += dp[j - coins[i]];//������ϵĵݹ鹫ʽ
			}
		}
		return dp[amount];
	}
};
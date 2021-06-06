#include<iostream>
#include<vector>
using namespace std;
//����ؼ���Ҫ�뵽���ƹ�ʽ����쳲������ĵ��ơ�������һ����ȷʵ�������뵽����
//�ϵ�i��¥���ж����ַ����أ����Բ��Ϊ��
//��i-1��+��1��
//��i-2��+��2��
//���ԣ�dp[i] = dp[i-1] + dp[i-2]����Ϊһ��ֻ����һ��������㣬���Է��İɣ�һ���������ģ���

//��һ�ֽǶȣ�����Ҳ���Կ���һ����ȫ�����������⣡����Ʒ2��������/��ֵ �ֱ���1��2����������Ϊn��
//class Solution {
//public:
//	int climbStairs(int n) {
//		int dp[2] = { 1,2 };//ע���ֵ������
//		int next = 0;
//		if (n <= 2) return n;
//		for (int i = 2; i < n; i++) {
//			next = dp[0] + dp[1];
//			dp[0] = dp[1];
//			dp[1] = next;
//		}
//		return next;
//	}
//};

//��һ�ֽǶȣ�����Ҳ���Կ���һ����ȫ�����������⣡����Ʒ2��������/��ֵ �ֱ���1��2����������Ϊn��
class Solution {
public:
	int climbStairs(int n) {
		int value[2] = { 1,2 };
		vector<int> dp(n + 1, 0);
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < 2; j++) {
				if (i - value[j]>=0) dp[i] += dp[i - value[j]];
			}
		}
		return dp[n];
	}
};
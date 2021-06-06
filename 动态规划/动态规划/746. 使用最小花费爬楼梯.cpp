#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//dp[i]���壺������i��¥�ݵ��ܻ���
//���ƣ�dp[i]=min(dp[i-1],dp[i-2])+cost[i]
//��ֵ����ע��
//������������ϱ��ܶ���ڸ��������Ŀ�����ǳ���⡣����̬�滮��˼�뻹����Ҫѧϰ��
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int dp[2] = { cost[0],cost[1] };//��ֵ
		for (int i = 2; i < cost.size(); i++) {
			int next = min(dp[0], dp[1]) + cost[i];
			dp[0] = dp[1];
			dp[1] = next;
		}
		//���Ҫȡdp���������Ԫ����С����Ϊ���ս������Ϊ��Ŀ˵����ѡ��ӵ�һ����ڶ������ݿ�ʼ�ߡ��������������Ԫ�طֱ����ӵ�һ��/�ڶ������ݿ�ʼ�Ľ��
		return min(dp[0], dp[1]);
	}
};
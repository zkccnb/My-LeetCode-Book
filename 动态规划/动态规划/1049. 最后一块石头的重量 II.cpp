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

//����416.�ָ�Ⱥ�����֮�󣬻ᷢ���������Ǹ���ʮ�����ƣ������Ƶ�����
//�о������Ҳ��Щ̰�ĵ���˼�����������Ž���ǣ�������ֳ����������飬ʹ���ߵĺ���ӽ����ٰѶ��ߵĺ������Ϊ���һ��ʯͷ��С������
class Solution {
public:
	int lastStoneWeightII(vector<int>& stones) {
		int target, total = 0;
		for (int i = 0; i < stones.size(); i++) total += stones[i];
		target = total / 2;
		//��416��ȫһ����ת����01����
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < stones.size(); i++) {
			for (int j = target; j >= stones[i]; j--) {
				dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
			}
		}
		return abs(total - 2 * dp[target]);//ֻ�������ص������� ���������������� �ĺ͵Ĳ�
	}
};
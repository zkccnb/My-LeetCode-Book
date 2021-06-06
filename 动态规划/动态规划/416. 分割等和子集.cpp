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

//���������û���ö��������������ǻᳬʱ����һ�������ǰ��������01���������ù�ʽ�����������������ô������ô������õ�����������
//01��������ָÿ����Ʒֻ����һ�εı������⡣����ȫ����ÿ����Ʒ�����������Σ�
//���ת����01�����أ�
//nums���鼴��v��������w���飬Ŀ��Ҳ��ȡ��ǰ��������������ֵ������������Ϊtargetʱ�������ʱ�����valueҲΪtarget��˵���ҵ���һ������ķָ
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int target = 0;
		for (int i = 0; i < nums.size(); i++) target += nums[i];
		if (target % 2) return false;
		target /= 2;//�ָ�Ⱥͣ���ʵ�������ҿ���û��һ���Ӽ�����͵���nums�����ܺ͵�һ�룬���ֵҲ��Ϊ�������������
		vector<int> dp(target + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = target; j >= nums[i]; j--) {
				dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
			}
		}
		return dp[target] == target;
	}
};
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//�����dp����ǳ����dp[i][j]�ĺ����ǣ�����i-j�Ƿ�Ϊ���Ĵ�������Ϊtrue������Ϊfalse��
//���ͳ��һ�¶�ά������true�ĸ�������
class Solution {
public:
	int countSubstrings(string s) {
		size_t s_s = s.size();
		int ret = 0;
		vector<vector<bool>> dp(s_s, vector<bool>(s_s, false));
		//������˳����Ҫע�⣬i����Ӻ���ǰ�Ų���©����jֻ�������i��ľ�����
		//����ζ�Ŷ�ά���������һ��û��ֵ��
		for (int i = s_s - 1; i >= 0; i--) {
			for (int j = i; j < s_s; j++) {
				if (s[i] == s[j])//���i-j����������ͬ����������п����ǻ��Ĵ�
				{
					//���ji���ڻ���ͬ����һ���ǻ��Ĵ���aa��a��
					if (j - i <= 1) { dp[i][j] = true; ret++; }
					else
					{
						//��������ַ���ͬ���м��������(i+1 - j-1)Ҳ�ǻ��Ĵ�����һ���ǻ��Ĵ�
						//�������էһ����̫����⡣����a bab a��
						if (dp[i + 1][j - 1] == true) { dp[i][j] = true; ret++; }
						else dp[i][j] = false;//����һ�����м䲻�ǻ��Ĵ���a bba a��
					}
				}
				else dp[i][j] = false;//�������i-j�����˲���ͬ���������һ�����ǻ��Ĵ���aacb��
			}
		}
		return ret;
	}
};
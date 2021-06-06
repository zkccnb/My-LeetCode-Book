#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//��ȫ��������ⷨ��(�������鷨��
//dp[j]���麬�壺��������Ϊjʱ����װ������ֵΪdp[j]
//dp�����ʼ����ȫ��
//���ƹ�ʽ��dp[j]=max(dp[j], dp[j-w[i]]+v[i])��while i=0-num��num����Ʒ�������ƹ�ʽ�����01����һ����������������˳���Ǵ�ǰ���01��������������˳���ǴӺ���ǰ��
//�����ƹ�ʽ��ô���أ������������dp[j]���Ը���dp������ļ����Ƴ��������⼸��ĵ��Ʊ��ʽ�����г��������⼸����Ƴ����ʽ����ʲô��ϵ����
//������ʽ������Ʒ����������ʵ���ڴ�������ȫ����������ɣ�����������ǰ���

//������������ˡ���������������ȫ���������Ǻ����뵽��ô����ת������ȫ����
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> word_set(wordDict.begin(), wordDict.end());
		size_t s_size = s.size();
		vector<bool> dp(s_size + 1, false);
		dp[0] = true;
		for (int i = 0; i < s_size + 1; i++) {
			for (int j = 0; j < i; j++) {
				string sub = s.substr(j, i - j);
				if (word_set.find(sub) != word_set.end() && dp[j]) { dp[i] = true; }
			}
		}
		return dp[s_size];
	}
};
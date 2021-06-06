#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
#include<map>
//һ��Ӧ���⣬�ӽ�hard�����ˣ��кܶ�ϸ�ڣ��о���������unordered_map<��������, map<�������, ���ִ��ֻ�Ʊ�Ĵ���>>�ṹ���Գ���-�����������ӳ��
//��Ϊ��Ҫ����ĳ������������ȫ������������������ֽṹ���Ժܺõ���ɱ�������
using namespace std;
class Solution {
public:
	vector<string> ret;
	size_t tickets_s;
	//���ﻹ��һ�����⣬map��ֵ���Ͳ�����bool����Ϊ�����л��ж��һģһ���Ļ�Ʊ������˵ӳ��ı�־ֵ����ֻ��0/1���������Ǻܶ࣡
	unordered_map<string, map<string, int>> mp;//����������Ӧ��n�����������ӳ�䣬ÿ��ӳ���Ӧһ����Ʊ��˳������map�����˻�Ʊ�Ƿ�����������ı�־��
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		tickets_s = tickets.size();
		//����ط����׺��ԣ�Ҫ�����ã����򿽱���Ԫ��Ҳ���ı�ԭֵ��
		for (auto& e_tkt : tickets) {
			mp[e_tkt[0]][e_tkt[1]]++;//��ʼ��ӳ�䣬ͬʱ���û�Ʊ�ı�־
		}
		ret.push_back("JFK");
		backtracking();
		return ret;
	}
	bool backtracking() {
		if (ret.size() == tickets_s + 1) return true;
		//��ӳ�����ҵ�ǰ����������Ӧ�����н������
		for (auto& e_pair : mp[ret[ret.size() - 1]]) {//����ط����׺��ԣ�Ҫ�����ã����򿽱���Ԫ��Ҳ���ı�ԭֵ��
			if (e_pair.second > 0)//��ǰ�Ļ�Ʊ��û������ݹ��
			{
				ret.push_back(e_pair.first);//�ѽ����������ret
				e_pair.second--;//���һ�������Ʊ�Ѿ��ù���
				if (backtracking()) return true;//�����һ��ݹ鷵��ֵΪtrue��˵���Ѿ��ҵ���ΨһҪ���·������ʱ��ͣ���Ϸ��ؼ���
				ret.pop_back();
				e_pair.second++;

			}
		}
		return false;
	}
};
#include<iostream>
#include<vector>
#include<algorithm>
//���һ��ʼ����ˣ���Ϊֻ��һ���ָ��߾����ˡ�����ϸ����������ô�������ֻ��һ���Ļ��ǻ��ݹ�ɶ����һ��ѭ���͸㶨�ˡ���
//����ָ��߿����кܶ��������Բ���Ҫ���µݹ���Ѱ����Щ�ָ������
//ÿ���µݹ�һ�Σ���Ե��������һ����ʵһ��������ǵ��͵ĵݹ��߼������
using namespace std;
class Solution {
public:
	vector<vector<string>> ret;
	vector<string> ret_line;
	string m_s;
	vector<vector<string>> partition(string s) {
		m_s = s;
		backtracking(0);
		return ret;
	}
	void backtracking(int cur) {
		if(cur>=m_s.size())//����������������ұߣ�˵���Ѿ��ҵ���һ����ȷ�ķָ�
		{
			ret.push_back(ret_line);
			return;
		}
		for (int i = cur; i < m_s.size(); i++) {
			//��ǰ�ķָ�Σ�cur-i���ǻ��Ĵ�����������ӵ�line��
			if (isPalindrome(m_s, cur, i)) ret_line.push_back(m_s.substr(cur,i-cur+1));
			//����ע�⣬�����ǰ�ķָ�ǻ��Ĵ���
			//continue�ᱣ����ǰ��ȷ����������ߵĴ�����������ǰ�ķָ��ߣ����ָ��߼��������ƶ�һ��
			else continue;
			backtracking(i + 1);
			ret_line.pop_back();
		}
	}
	bool isPalindrome(const string& s, int start, int end) {
		for (int left = start, right = end; left < right; left++, right--) {
			if (s[left] == s[right]) continue;
			else return false;
		}
		return true;
	}
};
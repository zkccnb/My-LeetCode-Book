#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		deque<string> dq;
		string stOfdq;
		size_t conti_num = 0;//连续空格的数量
		for (auto p_s=s.begin();p_s!=s.end();p_s++)
		{
			if (*p_s == ' ')
			{
				conti_num++;
				if (conti_num == 1)
				{
					stOfdq.push_back(' ');
					dq.push_front(stOfdq);
					stOfdq.clear();
				}
			}
			else
			{
				stOfdq.push_back(*p_s);
				conti_num = 0;
				if (p_s == s.end()-1)
				{
					stOfdq.push_back(' ');
					dq.push_front(stOfdq);
					stOfdq.clear();
				}
			}
		}
		s.clear();
		for (const auto e_dq : dq)
		{
			for (const auto e_e_dq : e_dq)
			{
				s.push_back(e_e_dq);
			}
		}
		while (*(s.end() - 1) == ' ') s.pop_back();
		return s;
	}
};


int main() {
	string s = "the sky is blue";
	string ret = Solution().reverseWords(s);
	for (const auto e_ret : ret) cout << e_ret;
	cout << endl;
}


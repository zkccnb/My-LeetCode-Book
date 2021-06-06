#include<iostream>
#include<vector>
#include<algorithm>
//这个一开始想简单了，以为只画一条分割线就行了。。仔细想想这样怎么可能嘛。。只画一条的话那还递归啥啊，一个循环就搞定了。。
//这个分割线可以有很多条，所以才需要向下递归来寻找这些分割嘛。。。
//每向下递归一次，面对的情况和上一次其实一样，这才是典型的递归逻辑嘛。。。
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
		if(cur>=m_s.size())//当横向遍历到了最右边，说明已经找到了一组正确的分割
		{
			ret.push_back(ret_line);
			return;
		}
		for (int i = cur; i < m_s.size(); i++) {
			//当前的分割段（cur-i）是回文串，把这个串加到line中
			if (isPalindrome(m_s, cur, i)) ret_line.push_back(m_s.substr(cur,i-cur+1));
			//这里注意，如果当前的分割不是回文串：
			//continue会保留当前已确定的所有左边的串，而跳过当前的分割线，将分割线继续向右移动一个
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
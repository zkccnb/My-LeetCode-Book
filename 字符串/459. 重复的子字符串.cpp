#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
using namespace std;
//这个题我怎么说呢。。。做下来整个人是懵逼的，甚至现在还不能完全搞懂。。是我做的最难的简单题了吧。。。
//我也没什么其他办法，多读读cral那篇文章吧。。实在不行到时候就背题。。
//匹配问题都不简单！
class Solution {
public:
	void getNext(int* &next, const string& s) {
		int j = -1;
		next[0] = j;
		for (auto i = 1; i < s.size(); i++)
		{
			while (j >= 0 && s[i] != s[j + 1]) j = next[j];//当前字符不匹配，向前回溯
			if (s[i] == s[j + 1]) j++;//当前字符匹配了，对应next数组值+1
			next[i] = j;//记录当前next数组值
		}
	}
	bool repeatedSubstringPattern(string s) {
		int* next = new int[s.size()];
		getNext(next, s);
		//记住，如果next数组尾元素值不为-1，且字符串长度可以整除数（字符串长度-组尾元素+1） -> 则一定由连续重复的子串构成
		//（字符串长度-组尾元素+1）的意义 ：当字符串由连续重复子串构成时，（字符串长度-组尾元素+1）就是重复子串的长度
		//自己写个next数组的例子，可以发现这一点。但是不这样告诉你的话估计你打死也想不到！！！
		//所以，面试前集中把这种题都背一下吧！
		if (next[s.size() - 1] != -1 && s.size() % (s.size() - (next[s.size() - 1] + 1)) == 0) { delete[] next; return true; }
		else { delete[] next; return false; }
	}
};

int main() {
	string h = "mississippi";
	string n = "sipp";
	/*string h = "aabaabaafcd";
	string n = "aabaaf";*/
	/*string h = "hello";
	string n = "ll";*/
	/*string h = "ccd";
	string n = "cd";*/
	int ret = Solution().repeatedSubstringPattern(h);
	cout << ret << endl;
}
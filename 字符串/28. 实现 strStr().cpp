#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
using namespace std;
//这个题我怎么说呢。。。做下来整个人是懵逼的，甚至现在还不能完全搞懂。。是我做的最难的简单题了吧。。。
//我也没什么其他办法，多读读cral那篇文章吧。。实在不行到时候就背题。。
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
	int strStr(string haystack, string needle) {
		if (!needle.size()) return 0;
		int* next = new int[needle.size()];
		int ptr_n = -1;
		getNext(next, needle);
		for (auto i = 0; i < haystack.size(); i++)
		{
			while(haystack[i] != needle[ptr_n + 1] && ptr_n != -1)//目前已有字符匹配上，但当前字符不匹配，needle指针回溯若干单位
			{
				//ptr_n -= (next[ptr_n - needle.begin() - 1] + 1);//needle迭代器前移这么多
				ptr_n = next[ptr_n];
			}
			if (haystack[i] == needle[ptr_n + 1])//当前字符匹配上了，两个指针都前移
			{
				ptr_n++;
			}
			if (ptr_n == needle.size()-1) return (i - needle.size() +1);
		}
		delete[] next;
		return -1;
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
	int ret = Solution().strStr(h,n);
	cout << ret << endl;
}
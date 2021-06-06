#include<iostream>
#include<vector>
//这个题要处理一下输入字符的转换，
//感觉做了前面两道题，这道题只要理清楚到底需要对什么递归和循环其实很容易写出来
using namespace std;
class Solution {
	vector<string> charMap = {
		"",//0
		"",//1
		"abc",//2
		"def",//3
		"ghi",//4
		"jkl",//5
		"mno",//6
		"pqrs",//7
		"tuv",//8
		"wxyz"//9
	};
	vector<int> index;//输入转换成整型数组
	vector<string> ret;
	string ret_line;
public:
	vector<string> letterCombinations(string digits) {
		if (!digits.size()) return ret;
		for (int i = 0; i < digits.size(); i++) {
			index.push_back((int)(digits[i] - '0'));
		}
		backtracking(index.size(), 0);
		return ret;
	}
	//deep：输入键的数目，递归的深度
	//cur：当前正在找第几个键对应的字母，当前递归的深度
	void backtracking(int deep, int cur) {
		if (cur == deep)
		{
			ret.push_back(ret_line);
			return;
		}
		int curSize = charMap[index[cur]].size();//当前递归到的数字对应字符串的长度
		for (int i = 0; i < curSize; i++) {
			ret_line.push_back(charMap[index[cur]][i]);
			backtracking(deep, cur + 1);
			ret_line.pop_back();
		}
	}
};
//int main()
//{
//	vector<vector<int>> ret = Solution().combine(4, 2);
//	for (int i = 0; i < ret.size(); i++) {
//		for (int j = 0; j < ret[i].size(); j++) {
//			cout << ret[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
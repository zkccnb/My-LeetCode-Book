#include<iostream>
#include<vector>
//�����Ҫ����һ�������ַ���ת����
//�о�����ǰ�������⣬�����ֻҪ�����������Ҫ��ʲô�ݹ��ѭ����ʵ������д����
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
	vector<int> index;//����ת������������
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
	//deep�����������Ŀ���ݹ�����
	//cur����ǰ�����ҵڼ�������Ӧ����ĸ����ǰ�ݹ�����
	void backtracking(int deep, int cur) {
		if (cur == deep)
		{
			ret.push_back(ret_line);
			return;
		}
		int curSize = charMap[index[cur]].size();//��ǰ�ݹ鵽�����ֶ�Ӧ�ַ����ĳ���
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
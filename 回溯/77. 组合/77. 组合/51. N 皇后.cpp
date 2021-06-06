#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
#include<map>
//N皇后是经典的回溯问题，面试很可能考到！
//关键是要想到，要横向遍历棋盘上的每一行，纵向递归棋盘中的列，而不是像解数独那样横向遍历整个n*n棋盘！那样感觉也不是不行。。但是计算量明显更大啊
using namespace std;
class Solution {
public:
	vector<vector<string>> ret;
	vector<string> ret_line;//棋盘
	int m_n;
	vector<vector<string>> solveNQueens(int n) {
		m_n = n;
		initchess();
		backtracking(0);
		return ret;
	}
	//cur是当前递归层数,也就是棋盘的行数
	//横向遍历棋盘上的每一行，纵向递归棋盘中的列
	void backtracking(int cur) {
		if (cur >= m_n)
		{
			ret.push_back(ret_line);
			return;
		}
		for (int i = 0; i < m_n; i++) {
			if (isValid(cur, i))
			{
				ret_line[cur][i] = 'Q';
				backtracking(cur + 1);
				ret_line[cur][i] = '.';
			}
		}
	}
	//初始化棋盘
	void initchess() {
		string chess_line(m_n, '.');
		vector<string> chess(m_n, chess_line);
		ret_line = chess;
	}
	//判断当前位置是否可以放皇后
	//仔细想想，只需判断：当前列（到最上面）是否有Q，当前位置的斜45度向上是否有Q，斜135度向上是否有Q
	bool isValid(int rol, int col) {
		//纵向判断列是否有Q
		for (int i = rol; i >= 0; i--) {
			if (ret_line[i][col] == 'Q') return false;
		}
		//斜45度判断是否有Q
		for (int i = rol, j = col; i >= 0 && j >= 0; i--, j--) {
			if (ret_line[i][j] == 'Q') return false;
		}
		//斜135度判断是否有Q
		for (int i = rol, j = col; i >= 0 && j >= 0; i--, j++) {
			if (ret_line[i][j] == 'Q') return false;
		}
		return true;
	}
};
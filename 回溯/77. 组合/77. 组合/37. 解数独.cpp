#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
#include<map>
//这次是每层横向遍历是一整个棋盘，纵向递归的是所有可能的情况。并不是像n皇后那样横纵遍历都是实体
//我感觉还是这种思维比较符合你
using namespace std;
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		backstracking(board);
	}
	bool backstracking(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') continue;
				for (char val = '1'; val <= '9'; val++) {
					if (isValid(i, j, val, board))
					{
						board[i][j] = val;
						if (backstracking(board)) return true;
						board[i][j] = '.';
					}
				}
				return false;
			}
		}
		return true;
	}
	bool isValid(int rol, int col, char val, const vector<vector<char>>& board) {
		//检查该列是否合法
		for (int i = 0; i < 9; i++) {
			if (board[i][col] == val) return false;
		}
		//检查该行是否合法
		for (int i = 0; i < 9; i++) {
			if (board[rol][i] == val) return false;
		}
		//检查当前九宫格是否合法
		int nineStartrol = (rol / 3) * 3;
		int nineStartcol = (col / 3) * 3;
		for (int i = nineStartrol; i < nineStartrol + 3; i++) {
			for (int j = nineStartcol; j < nineStartcol + 3; j++) {
				if (board[i][j] == val) return false;
			}
		}
		return true;
	}
};
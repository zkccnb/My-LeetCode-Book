#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
#include<map>
//�����ÿ����������һ�������̣�����ݹ�������п��ܵ��������������n�ʺ��������ݱ�������ʵ��
//�Ҹо���������˼ά�ȽϷ�����
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
		//�������Ƿ�Ϸ�
		for (int i = 0; i < 9; i++) {
			if (board[i][col] == val) return false;
		}
		//�������Ƿ�Ϸ�
		for (int i = 0; i < 9; i++) {
			if (board[rol][i] == val) return false;
		}
		//��鵱ǰ�Ź����Ƿ�Ϸ�
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
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
#include<map>
//N�ʺ��Ǿ���Ļ������⣬���Ժܿ��ܿ�����
//�ؼ���Ҫ�뵽��Ҫ������������ϵ�ÿһ�У�����ݹ������е��У�����������������������������n*n���̣������о�Ҳ���ǲ��С������Ǽ��������Ը���
using namespace std;
class Solution {
public:
	vector<vector<string>> ret;
	vector<string> ret_line;//����
	int m_n;
	vector<vector<string>> solveNQueens(int n) {
		m_n = n;
		initchess();
		backtracking(0);
		return ret;
	}
	//cur�ǵ�ǰ�ݹ����,Ҳ�������̵�����
	//������������ϵ�ÿһ�У�����ݹ������е���
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
	//��ʼ������
	void initchess() {
		string chess_line(m_n, '.');
		vector<string> chess(m_n, chess_line);
		ret_line = chess;
	}
	//�жϵ�ǰλ���Ƿ���ԷŻʺ�
	//��ϸ���룬ֻ���жϣ���ǰ�У��������棩�Ƿ���Q����ǰλ�õ�б45�������Ƿ���Q��б135�������Ƿ���Q
	bool isValid(int rol, int col) {
		//�����ж����Ƿ���Q
		for (int i = rol; i >= 0; i--) {
			if (ret_line[i][col] == 'Q') return false;
		}
		//б45���ж��Ƿ���Q
		for (int i = rol, j = col; i >= 0 && j >= 0; i--, j--) {
			if (ret_line[i][j] == 'Q') return false;
		}
		//б135���ж��Ƿ���Q
		for (int i = rol, j = col; i >= 0 && j >= 0; i--, j++) {
			if (ret_line[i][j] == 'Q') return false;
		}
		return true;
	}
};
#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//一种十分巧妙的方法
//分两步，行反转->取转置->over
//可见，对数组、矩阵、字符串等顺序结构的旋转均能用多次反转求得！而这种方法在面试中多试试还是相对容易想到的（总比你疯狂的操作要容易想吧。。。）
//但是这种方法在时间上不是最快的，是一种糟糕的O(n2)。
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		reverse(matrix.begin(), matrix.end());//行反转
		for (int i = 0; i < matrix.size(); i++) {//转置
			for (int j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};
int main() {
	vector<vector<int>> matrix = { {1, 2, 3},{5, 6, 7},{9, 10, 11} };
	Solution().rotate(matrix);
	for (auto i = 0; i < matrix.size(); i++) {
		for (auto j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
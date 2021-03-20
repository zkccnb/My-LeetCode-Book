#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int rol = matrix.size(), col = matrix[0].size();
		int top = 0, bottom = rol, left = 0, right = col;
		int num = 0;
		vector<int> ret;
		while (num<rol*col) {
			for (int i = left; i < right; i++) {//上左->上右
				ret.push_back(matrix[top][i]);
				num++;
			}
			for (int i = top+1; i < bottom; i++) {//上右->下右
				ret.push_back(matrix[i][right - 1]);
				num++;
			}
			if (bottom-top > 1 && right - left > 1)
			{
				for (int i = right - 2; i >= left; i--) {//下右->下左
					ret.push_back(matrix[bottom - 1][i]);
					num++;
				}
				for (int i = bottom - 2; i > top; i--) {//下左->上左
					ret.push_back(matrix[i][left]);
					num++;
				}
			}
			left++; top++; right--; bottom--;
		}
		return ret;
	}
};
int main() {
	vector<vector<int>> vec = { {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12} };
	vector<int> ret = Solution().spiralOrder(vec);
	for (auto i = 0; i < ret.size(); i++) cout << ret[i] << ' ';
	cout << endl;
}
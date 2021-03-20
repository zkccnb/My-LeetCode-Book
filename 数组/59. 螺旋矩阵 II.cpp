#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	typedef vector<vector<int>> ret_t;
	vector<vector<int>> generateMatrix(int n) {
		ret_t ret(n, vector<int>(n, 0));
		int left = 0, right = n, top = 0, bottom = n, num = 0;
		while (num < n * n) {
			for (int i = left; i < right; i++) {
				ret[top][i] = ++num;
			}
			for (int i = top + 1; i < bottom; i++) {
				ret[i][right - 1] = ++num;
			}
			if (bottom - top > 1 && right - left > 1)
			{
				for (int i = right - 2; i > left; i--) {
					ret[bottom - 1][i] = ++num;
				}
				for (int i = bottom - 1; i > top; i--) {
					ret[i][left] = ++num;
				}
			}
			left++; right--; top++; bottom--;
		}
		return ret;
	}
};
int main() {
	int num = 3;
	Solution::ret_t ret = Solution().generateMatrix(num);
	for (auto i = 0; i < ret.size(); i++) {
		for (auto j = 0; j < ret[0].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
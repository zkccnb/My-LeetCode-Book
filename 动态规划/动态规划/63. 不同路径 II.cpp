#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		bool flag_x = false, flag_y = false;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		//第一列初始化
		for (int i = 0; i < m; i++)
		{
			if (obstacleGrid[i][0] == 1 || flag_y)
			{
				flag_y = true;
				obstacleGrid[i][0] = 0;
			}
			else obstacleGrid[i][0] = 1;
		}
		//第一行初始化
		for (int i = 1; i < n; i++)
		{
			if (obstacleGrid[0][i] == 1 || flag_x)
			{
				flag_x = true;
				obstacleGrid[0][i] = 0;
			}
			else obstacleGrid[0][i] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
				else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			}
		}
		return obstacleGrid[m - 1][n - 1];
	}
};
//int main() {
//	vector<vector<int>> obs = { {1,0 }};
//	int ret=Solution().uniquePathsWithObstacles(obs);
//	int m = obs.size(), n = obs[0].size();
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << obs[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	//cout << ret << endl;
//}
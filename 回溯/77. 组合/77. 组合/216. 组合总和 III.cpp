#include<iostream>
#include<vector>
using namespace std;
//写回溯函数的时候，往往在循环外面进行一次判断就够了
//此时如果还能到循环里面，就说明是判断的另一个分支了，在循环里写ifelse太容易错了
//刚开始做回溯做不出来我感觉很正常，还是要多画画递归链路图，找找思路
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> ret_line;
	int cur_sum;
	vector<vector<int>> combinationSum3(int k, int n) {
		cur_sum = 0;
		backtracking(k, n, 1);
		return ret;
	}
	void backtracking(int k, int n, int cur) {
		if (cur_sum > n) return;//最好在最前面剪枝
		if (ret_line.size() == k)
		{
			if (cur_sum == n) ret.push_back(ret_line);
			return;
		}
		//再剪一次
		for (int i = cur; i < (10 < n ? 10 : n); i++) {
			ret_line.push_back(i);
			cur_sum += i;
			backtracking(k, n, i + 1);
			cur_sum -= i;
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
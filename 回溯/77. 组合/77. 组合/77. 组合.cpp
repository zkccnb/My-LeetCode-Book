#include<iostream>
#include<vector>
//回溯的经典写法，撤销的处理是为了可以回溯到最上层
//建议这个题看的时候把所有语句全部打上断点挨个单步运行，厘清其中的递归路径

using namespace std;
class Solution {
private:
	vector<vector<int>> result; // 存放符合条件结果的集合
	vector<int> path; // 用来存放符合条件结果
	void backtracking(int n, int k, int startIndex) {
		if (path.size() == k) {
			result.push_back(path);
			return;
		}
		//这里可以做一个剪枝：当前还需要选k-path.size()个元素到路径（已经选了path.size()个元素）
		for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
			path.push_back(i); // 处理节点 
			backtracking(n, k, i + 1); // 递归
			path.pop_back(); // 回溯，撤销处理的节点，这个地方是精髓！
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		result.clear(); // 可以不写
		path.clear();   // 可以不写
		backtracking(n, k, 1);
		return result;
	}
};
//这种写法是把line当作每一层递归的参数，但即便是这样也必须撤销操作才行!
//回溯/递归的设计一定要画画递归链路，把每一层递归栈里的变量画出来，这样一目了然
//class Solution {
//private:
//	vector<vector<int>> ret; // 存放符合条件结果的集合
//	//vector<int> ret_line; // 用来存放符合条件结果
//	void backtracking(int n, int k, int startIndex, vector<int> ret_line) {
//		if (ret_line.size() == k) {
//			ret.push_back(ret_line);
//			return;
//		}
//		for (int i = startIndex; i <= n; i++) {
//			ret_line.push_back(i); // 处理节点 
//			backtracking(n, k, i + 1,ret_line); // 递归
//			ret_line.pop_back(); // 回溯，撤销处理的节点，这个地方是精髓！
//		}
//	}
//public:
//	vector<vector<int>> combine(int n, int k) {
//		backtracking(n, k, 1, {});
//		return ret;
//	}
//};
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
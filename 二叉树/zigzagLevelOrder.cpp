#include"TreeNode.h"
//103. 二叉树的锯齿形层序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//		queue<TreeNode*> q;
//		vector<vector<int>> ret;
//		int size_q = 0;
//		q.push(root);
//		TreeNode* front = nullptr;
//		int row = 0;
//		while (!q.empty()) {
//			row++;
//			vector<int> line;
//			size_q = q.size();
//			for (int i = 0; i < size_q; i++) {
//				front = q.front();
//				if (front)
//				{
//					line.push_back(front->val);
//					q.push(front->left); q.push(front->right);
//				}
//				q.pop();
//			}
//			if (!(row % 2)) reverse(line.begin(), line.end());
//			if (line.size()) ret.push_back(line);
//		}
//		return ret;
//	}
//};
//把行数组换成一个双端队列，就不用费劲reverse了！
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ret;
		int size_q = 0;
		q.push(root);
		TreeNode* front = nullptr;
		int row = 0;
		while (!q.empty()) {
			row++;
			deque<int> line;
			size_q = q.size();
			for (int i = 0; i < size_q; i++) {
				front = q.front();
				if (front)
				{
					//这里根据行数奇偶决定头插还是尾插
					if (!(row % 2)) line.push_front(front->val);
					else line.push_back(front->val);
					q.push(front->left); q.push(front->right);
				}
				q.pop();
			}
			if (line.size()) ret.emplace_back(line.begin(), line.end());//emplace可以直接调用模板类型的构造函数
		}
		return ret;
	}
};
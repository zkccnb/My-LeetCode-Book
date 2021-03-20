#include"TreeNode.h"
//102. 二叉树的层序遍历
//层序遍历和另三种不一样，属于广度优先遍历，不好用递归
 //广度用队列，深度用栈
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> qN;
		vector<vector<int>> ret;

		if (root) qN.push(root);
		while (!qN.empty()) {
			int size = qN.size();
			vector<int> ret_rol;
			for (int i = 0; i < size; i++) {
				ret_rol.push_back(qN.front()->val);
				if (qN.front()->left) qN.push(qN.front()->left);
				if (qN.front()->right) qN.push(qN.front()->right);
				qN.pop();
			}
			ret.push_back(ret_rol);
		}
		return ret;
	}
};
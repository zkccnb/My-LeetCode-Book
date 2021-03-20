#include"TreeNode.h"
//107. 二叉树的层序遍历 II
//层序遍历和另三种不一样，属于广度优先遍历，不好用递归
 //自顶向下的层序遍历后把结果reverse
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ret;
		TreeNode* temp;
		size_t size = 0;
		q.push(root);
		while (!q.empty()) {
			size = q.size();
			vector<int> ret_L;
			for (int i = 0; i < size; i++) {
				temp = q.front();
				if (temp)
				{
					ret_L.push_back(temp->val);
					if (temp->left) q.push(temp->left);
					if (temp->right) q.push(temp->right);
				}
				q.pop();
			}
			if (!ret_L.empty()) ret.push_back(ret_L);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};
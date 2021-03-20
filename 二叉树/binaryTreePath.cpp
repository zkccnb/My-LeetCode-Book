#include"TreeNode.h"
//257. 二叉树的所有路径
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
class Solution {
public:
	vector<string> ret;
	vector<string> binaryTreePaths(TreeNode* root) {
		string str;
		if (root) preOrder(root, str);
		return ret;
	}
	void preOrder(TreeNode* node, string s) {
		if (node->left || node->right)
		{
			s += to_string(node->val) + "->";
			if (node->left) preOrder(node->left, s);
			if (node->right) preOrder(node->right, s);
		}
		else
		{
			s += to_string(node->val);
			ret.push_back(s);
		}
	}
};
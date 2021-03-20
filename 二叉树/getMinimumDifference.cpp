#include"TreeNode.h"
//530. 二叉搜索树的最小绝对差
//搜索树的中序遍历逻辑是不变的，但是我自己写的时候卡在了返回值上，递归函数是否真的需要返回值还是要仔细斟酌的
//其实很多时候有返回值的递归函数反而会把你限制死了，去刷一个成员变量（或者全局变量）有时更好解决问题
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
	TreeNode* pre_n;
	int ret = INT_MAX;
	int getMinimumDifference(TreeNode* root) {
		inOrder(root);
		return ret;
	}
	void inOrder(TreeNode* root) {
		if (!root) return;
		getMinimumDifference(root->left);
		int cur_diff = ret;
		if (pre_n) cur_diff = root->val - pre_n->val;
		ret = cur_diff < ret ? cur_diff : ret;
		pre_n = root;
		getMinimumDifference(root->right);
	}
};
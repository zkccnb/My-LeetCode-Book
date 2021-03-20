#include"TreeNode.h"
//110. Æ½ºâ¶þ²æÊ÷
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
	bool returnFlag;
	bool isBal;
	bool isBalanced(TreeNode* root) {
		returnFlag = false;
		isBal = true;
		postOrder(root);
		return isBal;
	}
	int postOrder(TreeNode* node) {
		if (!node) return 0;
		if (returnFlag) return -1;
		int leftH = postOrder(node->left);
		int rightH = postOrder(node->right);
		if (abs(leftH - rightH) > 1) { returnFlag = true; isBal = false; return -1; }
		else return max(leftH, rightH) + 1;
	}
};
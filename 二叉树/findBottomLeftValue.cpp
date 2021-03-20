#include"TreeNode.h"
//513. ÕÒÊ÷×óÏÂ½ÇµÄÖµ
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
	int deep;
	int ret;
	//bool isLeft;
	int findBottomLeftValue(TreeNode* root) {
		postOrder(root,false);
		return ret;
	}
	void postOrder(TreeNode* node,bool isLeft) {
		if (!node) return;
		int _deep = ++deep;
		postOrder(node->left,true);
		postOrder(node->right,false);
		if (isLeft && _deep >= deep) ret = node->val;
	}
};
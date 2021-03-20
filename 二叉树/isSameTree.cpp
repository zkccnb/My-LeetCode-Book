#include"TreeNode.h"
//100. ÏàÍ¬µÄÊ÷
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
	bool returnF;
	bool isSameTree(TreeNode* p, TreeNode* q) {
		returnF = false;
		preOrder(p, q);
		return !returnF;
	}
	void preOrder(TreeNode* node1, TreeNode* node2) {
		if (returnF) return;
		if (node1&&node2)
		{
			if (node1->val == node2->val)
			{
				preOrder(node1->left, node2->left);
				preOrder(node1->right, node2->right);
			}
			else
			{
				returnF = true;
				return;
			}
		}
		else if (!node1 && !node2) return;
		else
		{
			returnF = true;
			return;
		}
	}
};
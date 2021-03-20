#include"TreeNode.h"
//236. 二叉树的最近公共祖先
//本质还是后序遍历，因为找祖先需要回溯，具体的逻辑看看carl的文章吧，这可能是我目前见过最绕的递归了
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//root是空，则返root(空)；如果root是p或q，返回自己，说明找到了p或q
		if (!root || root->val == p->val || root->val == q->val) return root;
		//后序遍历，用来回溯
		TreeNode* is_left = lowestCommonAncestor(root->left, p, q);
		TreeNode* is_right = lowestCommonAncestor(root->right, p, q);
		//左边和右边哪个节点返回值不是空，就说明这个节点或其子树中，含有p或q
		if (is_left && !is_right) return is_left;
		else if (!is_left && is_right) return is_right;
		//如果左右节点返回值都不是空，说明此时刚好第一次找到p和q的公共父节点，以后都应返回这个
		else if (is_left && is_right) return root;
		else return NULL;
	}
};
//235. 二叉搜索树的最近公共祖先
//如果是搜索树的话就简单多了
//class Solution {
//public:
//	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//		if (!root) return NULL;
//		if (q->val > p->val)
//		{
//			if (root->val >= p->val && root->val <= q->val) return root;
//			if (root->val < p->val) root = lowestCommonAncestor(root->right, p, q);
//			if (root->val > q->val) root = lowestCommonAncestor(root->left, p, q);
//		}
//		else
//		{
//			if (root->val <= p->val && root->val >= q->val) return root;
//			if (root->val > p->val) root = lowestCommonAncestor(root->left, p, q);
//			if (root->val < q->val) root = lowestCommonAncestor(root->right, p, q);
//		}
//		return root;
//
//	}
//};
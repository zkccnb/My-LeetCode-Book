#include"TreeNode.h"
//104. 二叉树的最大深度
//559. N 叉树的最大深度
//不是很难，层序，前序，后序遍历都可
//n叉树和二叉树的思路、写法很类似，稍微变通一下就行了
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
	int ret;//一个成员变量，记录最终的结果
	int maxDepth(TreeNode* root) {
		if (root) preOrder(root, 0);//这个初值很重要，不能弄错了
		return ret;
	}
	void preOrder(TreeNode* node, int cur_d) {
		if (node) ret = ret >= ++cur_d ? ret : cur_d;//这里ret需要记录的是历史最大值，而不是当前值
		else return;
		preOrder(node->left, cur_d);
		preOrder(node->right, cur_d);
	}

};
#include"TreeNode.h"
//669. 修剪二叉搜索树
//注意，这个题绝对不能用删除节点来做，那样根本不行，老老实实重新想办法吧
//可以发现，对于搜索二叉树来说：如果发现一个节点的值大于了修剪范围，那么这个节点的右子树都要删掉
//如果发现一个节点的值小于了修剪范围，那么这个节点的左子树都要删掉
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
//有返回值的递归，但有返回值的递归我好像还是用不习惯啊！
//不过你自己试着写写这个题没有返回值的版本，就会发现好像不太好写
//需要一个返回值去替换掉当前的节点！
class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) return nullptr;
		if (root->val > high)
		{
			root = trimBST(root->left, low, high);//用左子树替换了当前节点，并返回
			return root;
		}
		if (root->val < low)
		{
			root = trimBST(root->right, low, high);//用右子树替换了当前节点，并返回
			return root;
		}
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}
};
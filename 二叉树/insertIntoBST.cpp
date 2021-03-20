#include"TreeNode.h"
//701. 二叉搜索树中的插入操作
//这题其实不难，但是要注意用返回值或者引用的手段来保存父节点下子节点的变化。
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
 // class Solution {
 // public:
 //     TreeNode* insertIntoBST(TreeNode* root, int val) {
 //         if(!root){root=new TreeNode(val);return root;}
 //         //这个题的递归逻辑其实是需要返回值的，因为需要当前节点的父节点把改动过的下面节点“接住”
 //         //最后的根节点才会有变化，如果没有返回值，一顿操作，但只改变了最下面难过节点，根节点没有变化！
 //         if(val>root->val) root->right=insertIntoBST(root->right,val);
 //         if(val<root->val) root->left=insertIntoBST(root->left,val);
 //         return root;
 //     }
 // };

class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		preOrder(root, val);
		return root;
	}
	//如果这里把参数类型改成引用，也可以实现保存父节点中子节点的改动，从而可以不用返回值
	void preOrder(TreeNode* &root, int val) {
		if (!root) { root = new TreeNode(val); return; }
		if (val > root->val) preOrder(root->right, val);
		if (val < root->val) preOrder(root->left, val);
	}
};
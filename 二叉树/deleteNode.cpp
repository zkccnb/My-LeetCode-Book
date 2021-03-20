#include"TreeNode.h"
//450. 删除二叉搜索树中的节点
//如果做了701. 插入节点，这个题就不难了
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
	TreeNode* deleteNode(TreeNode* root, int key) {
		returnFlag = false;
		preOrder_del(root, key);
		return root;
	}
	void preOrder_del(TreeNode* &root, int key) {
		if (!root || returnFlag) return;//空节点返回，找到要删除的目标节点返回
		if (root->val == key)//找到了目标节点
		{
			//此时，把左子树按照701题插入的方法插入到右子树中，再把当前节点用插入后的节点替换掉
			if (!root->left) root = root->right;//如果左子树为空，直接用右子树替换当前节点就行了
			else//插入后再替换
			{
				root->right = insertIntoBST(root->right, root->left);
				root = root->right;
			}
			returnFlag = true;
			return;
		}
		//前序遍历，寻找待删除的目标节点
		preOrder_del(root->left, key);
		preOrder_del(root->right, key);
	}
	TreeNode* insertIntoBST(TreeNode* root, TreeNode* insert) {
		preOrder_insert(root, insert);
		return root;
	}
	//如果这里把参数类型改成引用，也可以实现保存父节点中子节点的改动，从而可以不用返回值
	void preOrder_insert(TreeNode* &root, TreeNode* insert) {
		if (!root) { root = insert; return; }
		if (insert->val > root->val) preOrder_insert(root->right, insert);
		if (insert->val < root->val) preOrder_insert(root->left, insert);
	}
};
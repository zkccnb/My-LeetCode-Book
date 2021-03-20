#include"TreeNode.h"
//98. 验证二叉搜索树
//这个题还是得用中序遍历做，十分简单，但是第一次极其不容易想到。

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
//其实如果懂了原理（搜索二叉树的中序遍历一定是有序的），可以不用把中序数组提取出来，直接边遍历边比较即可，时间复杂度为O(n),空间复杂度为O(1)（不算递归栈空间）
//这种写法也是搜索树必须掌握的操作！
//class Solution {
//public:
//	TreeNode* pre;
//	bool isValidBST(TreeNode* root) {
//		if (!root) return true;
//		bool left = isValidBST(root->left);
//		if (pre && pre->val >= root->val) return false;
//		pre = root;
//		bool right = isValidBST(root->right);
//		return left && right;
//	}
//};
//这也是直接递归的写法，但没有返回值，刷成员变量。
//这种写法个人认为比较清晰，因为这样就把刷新目标值 和 递归返回 这两个过程分割开来，而不是像有返回值那样混在一起，有时候会限制操作。
class Solution {
public:
	TreeNode* pre;
	bool returnFlag;
	bool isValidBST(TreeNode* root) {
		returnFlag = false;
		inOrder(root);
		return !returnFlag;
	}
	void inOrder(TreeNode* root) {
		if (!root || returnFlag) return;
		inOrder(root->left);
		if (pre && pre->val >= root->val) returnFlag = true;
		pre = root;
		inOrder(root->right);
	}
};
//这里是把中序数组提取出来然后再遍历一遍比较，时间复杂度是O(n+n)，空间复杂度为O(n)（不算递归栈空间）
//class Solution {
//public:
//	vector<int> inOrderVec;
//	bool isValidBST(TreeNode* root) {
//		inOrder(root);
//		for (int i = 1; i < inOrderVec.size(); i++) {
//			if (inOrderVec[i] <= inOrderVec[i - 1]) return false;
//		}
//		return true;
//	}
//	void inOrder(TreeNode* node) {
//		if (!node) return;
//		inOrder(node->left);
//		inOrderVec.push_back(node->val);
//		inOrder(node->right);
//	}
//};
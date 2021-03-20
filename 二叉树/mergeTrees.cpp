#include"TreeNode.h"
//617. �ϲ�������
//��һ������Ĺ����������Ŀ����������ҩ���Թ���������ݹ�д�������Ļ�����⻹����������
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
	TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
		TreeNode* node;
		if (root1 && root2)
		{
			node = new TreeNode(root1->val + root2->val);
			node->left = mergeTrees(root1->left, root2->left);
			node->right = mergeTrees(root1->right, root2->right);
		}
		else if (!root1 && root2)
		{
			node = new TreeNode(root2->val);
			node->left = mergeTrees(nullptr, root2->left);
			node->right = mergeTrees(nullptr, root2->right);
		}
		else if (root1 && !root2)
		{
			node = new TreeNode(root1->val);
			node->left = mergeTrees(root1->left, nullptr);
			node->right = mergeTrees(root1->right, nullptr);
		}
		else return nullptr;
		return node;
	}
};
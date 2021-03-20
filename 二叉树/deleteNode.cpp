#include"TreeNode.h"
//450. ɾ�������������еĽڵ�
//�������701. ����ڵ㣬�����Ͳ�����
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
		if (!root || returnFlag) return;//�սڵ㷵�أ��ҵ�Ҫɾ����Ŀ��ڵ㷵��
		if (root->val == key)//�ҵ���Ŀ��ڵ�
		{
			//��ʱ��������������701�����ķ������뵽�������У��ٰѵ�ǰ�ڵ��ò����Ľڵ��滻��
			if (!root->left) root = root->right;//���������Ϊ�գ�ֱ�����������滻��ǰ�ڵ������
			else//��������滻
			{
				root->right = insertIntoBST(root->right, root->left);
				root = root->right;
			}
			returnFlag = true;
			return;
		}
		//ǰ�������Ѱ�Ҵ�ɾ����Ŀ��ڵ�
		preOrder_del(root->left, key);
		preOrder_del(root->right, key);
	}
	TreeNode* insertIntoBST(TreeNode* root, TreeNode* insert) {
		preOrder_insert(root, insert);
		return root;
	}
	//�������Ѳ������͸ĳ����ã�Ҳ����ʵ�ֱ��游�ڵ����ӽڵ�ĸĶ����Ӷ����Բ��÷���ֵ
	void preOrder_insert(TreeNode* &root, TreeNode* insert) {
		if (!root) { root = insert; return; }
		if (insert->val > root->val) preOrder_insert(root->right, insert);
		if (insert->val < root->val) preOrder_insert(root->left, insert);
	}
};
#include"TreeNode.h"
//701. �����������еĲ������
//������ʵ���ѣ�����Ҫע���÷���ֵ�������õ��ֶ������游�ڵ����ӽڵ�ı仯��
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
 //         //�����ĵݹ��߼���ʵ����Ҫ����ֵ�ģ���Ϊ��Ҫ��ǰ�ڵ�ĸ��ڵ�ѸĶ���������ڵ㡰��ס��
 //         //���ĸ��ڵ�Ż��б仯�����û�з���ֵ��һ�ٲ�������ֻ�ı����������ѹ��ڵ㣬���ڵ�û�б仯��
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
	//�������Ѳ������͸ĳ����ã�Ҳ����ʵ�ֱ��游�ڵ����ӽڵ�ĸĶ����Ӷ����Բ��÷���ֵ
	void preOrder(TreeNode* &root, int val) {
		if (!root) { root = new TreeNode(val); return; }
		if (val > root->val) preOrder(root->right, val);
		if (val < root->val) preOrder(root->left, val);
	}
};
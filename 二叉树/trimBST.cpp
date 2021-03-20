#include"TreeNode.h"
//669. �޼�����������
//ע�⣬�������Բ�����ɾ���ڵ������������������У�����ʵʵ������취��
//���Է��֣�����������������˵���������һ���ڵ��ֵ�������޼���Χ����ô����ڵ����������Ҫɾ��
//�������һ���ڵ��ֵС�����޼���Χ����ô����ڵ����������Ҫɾ��
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
//�з���ֵ�ĵݹ飬���з���ֵ�ĵݹ��Һ������ò�ϰ�߰���
//�������Լ�����дд�����û�з���ֵ�İ汾���ͻᷢ�ֺ���̫��д
//��Ҫһ������ֵȥ�滻����ǰ�Ľڵ㣡
class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) return nullptr;
		if (root->val > high)
		{
			root = trimBST(root->left, low, high);//���������滻�˵�ǰ�ڵ㣬������
			return root;
		}
		if (root->val < low)
		{
			root = trimBST(root->right, low, high);//���������滻�˵�ǰ�ڵ㣬������
			return root;
		}
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root;
	}
};
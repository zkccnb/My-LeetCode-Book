#include"TreeNode.h"
//236. �������������������
//���ʻ��Ǻ����������Ϊ��������Ҫ���ݣ�������߼�����carl�����°ɣ����������Ŀǰ�������Ƶĵݹ���
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
		//root�ǿգ���root(��)�����root��p��q�������Լ���˵���ҵ���p��q
		if (!root || root->val == p->val || root->val == q->val) return root;
		//�����������������
		TreeNode* is_left = lowestCommonAncestor(root->left, p, q);
		TreeNode* is_right = lowestCommonAncestor(root->right, p, q);
		//��ߺ��ұ��ĸ��ڵ㷵��ֵ���ǿգ���˵������ڵ���������У�����p��q
		if (is_left && !is_right) return is_left;
		else if (!is_left && is_right) return is_right;
		//������ҽڵ㷵��ֵ�����ǿգ�˵����ʱ�պõ�һ���ҵ�p��q�Ĺ������ڵ㣬�Ժ�Ӧ�������
		else if (is_left && is_right) return root;
		else return NULL;
	}
};
//235. �����������������������
//������������Ļ��ͼ򵥶���
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
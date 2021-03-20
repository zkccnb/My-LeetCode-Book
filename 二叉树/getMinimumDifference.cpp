#include"TreeNode.h"
//530. ��������������С���Բ�
//����������������߼��ǲ���ģ��������Լ�д��ʱ�����˷���ֵ�ϣ��ݹ麯���Ƿ������Ҫ����ֵ����Ҫ��ϸ���õ�
//��ʵ�ܶ�ʱ���з���ֵ�ĵݹ麯������������������ˣ�ȥˢһ����Ա����������ȫ�ֱ�������ʱ���ý������
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
	TreeNode* pre_n;
	int ret = INT_MAX;
	int getMinimumDifference(TreeNode* root) {
		inOrder(root);
		return ret;
	}
	void inOrder(TreeNode* root) {
		if (!root) return;
		getMinimumDifference(root->left);
		int cur_diff = ret;
		if (pre_n) cur_diff = root->val - pre_n->val;
		ret = cur_diff < ret ? cur_diff : ret;
		pre_n = root;
		getMinimumDifference(root->right);
	}
};
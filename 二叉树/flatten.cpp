#include"TreeNode.h"
//114. ������չ��Ϊ����
//�����������������ʱ����ܻ����������Ϊ���۵�������������ֱ�Ӷ�rootָ����б��������
//���Ƕ�ԭrootָ���е��ڴ浥Ԫ���б��������
//�����ζ�ţ����Ǳ����ָ����С���ֵ�����á����ʣ�����۸��ڴ��е����ݣ�������������ͨ������
//������������ֱ��⡰��ֵ�����á���д����ʼ�ղ��ܸı�ԭrootָ��ָ���ڴ��е����ݣ�
//���������Ȼ��ȷ�ı���rootָ���ָ�򣬵�ԭrootָ��ָ����ڴ�ֵ��û�䣬�޷�ͨ�����⣡
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
//���ǵ�һ��д������ԭ���㷨��ʱ�临�Ӷȣ�O(n+n)���ռ临�Ӷȣ�O(n)
class Solution {
public:
	vector<TreeNode*> node;
	void flatten(TreeNode* root) {
		preOrder(root);
		if (!node.empty())
		{
			TreeNode* cur = node[0];
			for (int i = 1; i < node.size(); i++) {
				cur->left = nullptr;
				cur->right = node[i];
				cur = cur->right;
			}
		}

	}
	void preOrder(TreeNode* _node) {
		if (_node) node.push_back(_node);
		else return;
		preOrder(_node->left);
		preOrder(_node->right);
	}
};
//����һ��ԭ���㷨��ʱ�临�Ӷ�:O(n),�ռ临�Ӷ�:O(1)
//�����ҵ���ǰ�ڵ�ġ�ǰ���ڵ㡱��һ���Եذѽڵ��ƶ���λ
//class Solution {
//public:
//	void flatten(TreeNode* root) {
//		TreeNode* cur = root;//��ǰ�ڵ㣬�����ұ���
//		TreeNode* prev;//ǰ���ڵ㣨��ǰ�ڵ�����������ҵĽڵ㣩
//		while (cur) {
//			if (cur->left)
//			{
//				prev = cur->left;
//				while (prev->right) prev = prev->right;
//				prev->right = cur->right;
//				cur->right = cur->left;
//				cur->left = nullptr;
//			}
//			cur = cur->right;
//		}
//	}
//
//};
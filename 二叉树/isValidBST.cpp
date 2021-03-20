#include"TreeNode.h"
//98. ��֤����������
//����⻹�ǵ��������������ʮ�ּ򵥣����ǵ�һ�μ��䲻�����뵽��

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
//��ʵ�������ԭ���������������������һ��������ģ������Բ��ð�����������ȡ������ֱ�ӱ߱����߱Ƚϼ��ɣ�ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)������ݹ�ջ�ռ䣩
//����д��Ҳ���������������յĲ�����
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
//��Ҳ��ֱ�ӵݹ��д������û�з���ֵ��ˢ��Ա������
//����д��������Ϊ�Ƚ���������Ϊ�����Ͱ�ˢ��Ŀ��ֵ �� �ݹ鷵�� ���������̷ָ�������������з���ֵ��������һ����ʱ������Ʋ�����
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
//�����ǰ�����������ȡ����Ȼ���ٱ���һ��Ƚϣ�ʱ�临�Ӷ���O(n+n)���ռ临�Ӷ�ΪO(n)������ݹ�ջ�ռ䣩
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
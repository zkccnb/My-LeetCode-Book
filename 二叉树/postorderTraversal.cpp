#include"TreeNode.h"
//145. �������ĺ������
//ǰ������ĵݹ�д����ѭ��д���������ǵݹ黹��ѭ�������������ǰ����������񣬾Ͳ�д�ˣ�
using namespace std;
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
//class Solution {
//public:
//	vector<int> ret;
//	vector<int> postorderTraversal(TreeNode* root) {
//		postorder(root);
//		return ret;
//	}
//	void postorder(TreeNode* node) {
//		if (!node) return;
//		postorder(node->left);
//		postorder(node->right);
//		ret.push_back(node->val);
//	}
//};
//ѭ��
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> ret;
		st.push(root);
		TreeNode* node;
		while (!st.empty()) {
			node = st.top();
			st.pop();
			if (node)
			{
				if (node->left) st.push(node->left);
				if (node->right) st.push(node->right);
				ret.push_back(node->val);
			}
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

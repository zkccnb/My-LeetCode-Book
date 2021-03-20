#include"TreeNode.h"
//94. ���������������
//��������ĵݹ�д����ѭ��д�������������ѭ��д���е��ƣ���ǰ�����һ��
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
 //�ݹ�
 //class Solution {
 //public:
 //    vector<int> ret;
 //    vector<int> inorderTraversal(TreeNode* root) {
 //        inorder(root);
 //        return ret;
 //    }
 //    void inorder(TreeNode* node){
 //        if(!node) return;
 //        inorder(node->left);
 //        ret.push_back(node->val);
 //        inorder(node->right);
 //    }
 //};
//ѭ��
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> st;
		TreeNode* cur = root;
		TreeNode* node = root;
		st.push(root);
		while (!st.empty()) {
			if (node && node->left) { node = node->left; st.push(node); }
			else
			{
				if (st.top()) ret.push_back(st.top()->val);
				cur = st.top();
				st.pop();
				if (cur && cur->right) { st.push(cur->right); node = cur->right; }
			}
		}
		return ret;
	}
};
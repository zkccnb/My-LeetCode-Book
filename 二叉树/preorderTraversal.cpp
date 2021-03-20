#include"TreeNode.h"
//144. 二叉树的前序遍历
//前序遍历的递归写法和循环写法（不论是递归还是循环，后序遍历和前序遍历都很像，就不写了）
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
// 递归
 //class Solution {
 //public:
 //    vector<int> preorderTraversal(TreeNode* root) {
 //        vector<int> ret;
 //        preorder(root, ret);
 //        return ret;
 //    }
 //    void preorder(TreeNode* node,vector<int>& vec){
 //        if(!node) return;
 //        vec.push_back(node->val);
 //        preorder(node->left,vec);
 //        preorder(node->right,vec);
 //    }
 //};
//循环
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
				if (node->right) st.push(node->right);
				if (node->left) st.push(node->left);
				ret.push_back(node->val);
			}
		}
		return ret;
	}
};

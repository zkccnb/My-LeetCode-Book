#include"TreeNode.h"
//二叉树的右视图，如果想到层序遍历的话这个题还是很好做的
//199. 二叉树的右视图
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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		queue<TreeNode*> q;
		size_t size = 0;
		TreeNode* temp;
		q.push(root);
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				temp = q.front();
				if (temp)
				{
					if (i == size - 1) ret.push_back(temp->val);
					if (temp->left) q.push(temp->left);
					if (temp->right) q.push(temp->right);
				}
				q.pop();
			}
		}
		return ret;
	}
};
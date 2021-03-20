#include"TreeNode.h"
//二叉树的层平均值，如果想到层序遍历的话这个题还是很好做的
//637. 二叉树的层平均值
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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ret;
		queue<TreeNode*> q;
		size_t size_q = 0;
		TreeNode* temp;
		q.push(root);
		double aver_L = 0;
		size_t size_L = 0;
		while (!q.empty()) {
			size_q = q.size();
			for (int i = 0; i < size_q; i++) {
				temp = q.front();
				if (temp)
				{
					aver_L += temp->val;
					size_L++;
					if (temp->left) q.push(temp->left);
					if (temp->right) q.push(temp->right);
				}
				q.pop();
			}
			aver_L /= size_L;
			ret.push_back(aver_L);
			aver_L = size_L = 0;
		}
		return ret;
	}
};
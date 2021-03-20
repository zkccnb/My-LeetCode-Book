#include"TreeNode.h"
//226.翻转二叉树
//层序遍历，前序遍历，后序遍历均可，只有中序遍历不行，我采用了层序遍历，我感觉这是最好理解的。
//应该熟练掌握所有遍历的写法
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
	TreeNode* invertTree(TreeNode* root) {
		queue<TreeNode*> q;
		size_t size_q = 0;
		q.push(root);
		TreeNode* front_q;
		while (!q.empty()) {
			TreeNode* temp;
			size_q = q.size();
			for (int i = 0; i < size_q; i++) {
				front_q = q.front();
				if (front_q && (front_q->left || front_q->right))
				{
					temp = front_q->left;
					front_q->left = front_q->right;
					front_q->right = temp;
					if (front_q->left) q.push(front_q->left);
					if (front_q->right) q.push(front_q->right);
				}
				q.pop();
			}
		}
		return root;
	}
};
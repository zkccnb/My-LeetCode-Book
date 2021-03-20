#include"TreeNode.h"
//654. 最大二叉树
//和105,106题构造二叉树非常类似，还比那个简单，看看105，106的步骤，构造二叉树类型题的递归过程其实很好理解。
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (!nums.size()) return nullptr;
		auto it_max = max_element(nums.begin(), nums.end());
		TreeNode* node = new TreeNode(*it_max);
		vector<int> nums_l(nums.begin(), it_max);
		vector<int> nums_r(it_max + 1, nums.end());
		node->left = constructMaximumBinaryTree(nums_l);
		node->right = constructMaximumBinaryTree(nums_r);
		return node;
	}
};
#include"TreeNode.h"
//501. 二叉搜索树中的众数
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
    vector<int> ret;
    int cur_count;
    int max_count;
    bool dup_flag;
    TreeNode* pre_n;
    vector<int> findMode(TreeNode* root) {
        dup_flag=false;
        cur_count=max_count=0;
        inOrder(root);
        return ret;
    }
    void inOrder(TreeNode* node){
        if(!node) return;
        inOrder(node->left);
		if (!pre_n) cur_count = 1;
		else if (node->val == pre_n->val) cur_count++;
		else cur_count = 1;
		pre_n = node;
		if (cur_count >= max_count)
		{
			if (cur_count > max_count) { ret.clear(); max_count = cur_count; }
			ret.push_back(node->val);
		}
        inOrder(node->right);
    }
};
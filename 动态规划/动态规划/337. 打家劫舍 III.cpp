#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//这个题最巧妙的地方在于其递推公式的含义：dp[2]
//dp[0]：不偷当前节点，后序遍历到此节点时可以获得的最大金额
//dp[1]：偷当前节点，后序遍历到此节点时可以获得的最大金额
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	int rob(TreeNode* root) {
		vector<int> max_money = postOrder(root);
		return max(max_money[0], max_money[1]);
	}
	//后序遍历：需要用到其子节点的最大金额计算结果，来确定当前节点的最大金额计算结果
	vector<int> postOrder(TreeNode* node) {
		if (!node) return { 0,0 };//如果当前节点为空，则不管抢不抢当前节点，最大金额都是0
		vector<int> left_max_money = postOrder(node->left);
		vector<int> right_max_money = postOrder(node->right);
		//不抢当前节点的话，遍历到此节点的最多金额：左节点抢与不抢的最大可能金额 + 右节点抢与不抢的最大可能金额
		int neg_rob_cur = max(left_max_money[0], left_max_money[1]) + max(right_max_money[0], right_max_money[1]);
		//抢当前节点的话，遍历到此节点的最多金额：当前节点金额 + 不抢左节点的最大可能金额 + 不抢右节点的最大可能金额
		int rob_cur = node->val + left_max_money[0] + right_max_money[0];
		return { neg_rob_cur,rob_cur };
	}
};
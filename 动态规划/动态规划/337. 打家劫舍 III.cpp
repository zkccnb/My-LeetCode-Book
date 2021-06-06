#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
//�����������ĵط���������ƹ�ʽ�ĺ��壺dp[2]
//dp[0]����͵��ǰ�ڵ㣬����������˽ڵ�ʱ���Ի�õ������
//dp[1]��͵��ǰ�ڵ㣬����������˽ڵ�ʱ���Ի�õ������
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
	//�����������Ҫ�õ����ӽڵ����������������ȷ����ǰ�ڵ������������
	vector<int> postOrder(TreeNode* node) {
		if (!node) return { 0,0 };//�����ǰ�ڵ�Ϊ�գ��򲻹���������ǰ�ڵ㣬������0
		vector<int> left_max_money = postOrder(node->left);
		vector<int> right_max_money = postOrder(node->right);
		//������ǰ�ڵ�Ļ����������˽ڵ��������ڵ����벻���������ܽ�� + �ҽڵ����벻���������ܽ��
		int neg_rob_cur = max(left_max_money[0], left_max_money[1]) + max(right_max_money[0], right_max_money[1]);
		//����ǰ�ڵ�Ļ����������˽ڵ��������ǰ�ڵ��� + ������ڵ�������ܽ�� + �����ҽڵ�������ܽ��
		int rob_cur = node->val + left_max_money[0] + right_max_money[0];
		return { neg_rob_cur,rob_cur };
	}
};
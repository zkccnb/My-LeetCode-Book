#include"TreeNode.h"
//104. ��������������
//559. N ������������
//���Ǻ��ѣ�����ǰ�򣬺����������
//n�����Ͷ�������˼·��д�������ƣ���΢��ͨһ�¾�����
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
	int ret;//һ����Ա��������¼���յĽ��
	int maxDepth(TreeNode* root) {
		if (root) preOrder(root, 0);//�����ֵ����Ҫ������Ū����
		return ret;
	}
	void preOrder(TreeNode* node, int cur_d) {
		if (node) ret = ret >= ++cur_d ? ret : cur_d;//����ret��Ҫ��¼������ʷ���ֵ�������ǵ�ǰֵ
		else return;
		preOrder(node->left, cur_d);
		preOrder(node->right, cur_d);
	}

};
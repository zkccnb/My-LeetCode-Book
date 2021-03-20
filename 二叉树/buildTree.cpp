#include"TreeNode.h"
//106. �����������������й��������
//��105��һ����ע�⣬���빹����������������Ҫ�����������ֻ����ǰ���������ͺ���������鲻��ȷ��Ψһ�Ķ���������
//�����ĵݹ��߼���������ǰ���������ڵ�
//��ϸ�����������ע�ͣ���������˼·����
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
	vector<int> m_postorder;
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return build(inorder, postorder);
	}
	TreeNode* build(vector<int>& inorder, vector<int>& postorder) {
		int size = inorder.size();//ע�⵽�����������С��һ����
		if (size == 0) return nullptr;//1. �����������Ϊ�գ�ֱ�ӷ��ؿսڵ�
		//2.1 �����������У��Һ�����������һ��ֵ
		auto it_in = find(inorder.begin(), inorder.end(), postorder[size - 1]);
		TreeNode* node = new TreeNode(*it_in);//2.2 ���ҵ���ֵ�½�һ���ڵ�
		//3. ���ҵ��ڵ��λ�÷ָ���������
		vector<int> inorder_l(inorder.begin(), it_in);
		vector<int> inorder_r(it_in + 1, inorder.end());
		//4. �������򡢺��������С�������������ʣ�ȥ�ָ��������
		vector<int> postorder_l(postorder.begin(), postorder.begin() + inorder_l.size());
		vector<int> postorder_r(postorder.begin() + inorder_l.size(), postorder.end() - 1);
		//5. ʣ�µ����齻���ݹ�ͺ��ˣ��߼����൱��ǰ�����
		node->left = build(inorder_l, postorder_l);
		node->right = build(inorder_r, postorder_r);
		//6. �������˷��ؽڵ�
		return node;
	}
};
#include"TreeNode.h"
//173. ����������������
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
//�����������������Ԫ�ض�Ū���������д����������ͺ��ˣ��뷨�򵥵��ǿռ临�Ӷ���O(n)nΪ�ڵ����
//class BSTIterator {
//public:
//	vector<int> data;
//	int index;
//	void inorder(TreeNode* node) {
//		index = 0;
//		if (!node) return;
//		inorder(node->left);
//		data.push_back(node->val);
//		inorder(node->right);
//	}
//	BSTIterator(TreeNode* root) {
//		inorder(root);
//	}
//
//	int next() {
//		return data[index++];
//	}
//
//	bool hasNext() {
//		return (index) < data.size();
//	}
//};
//��ջ����ݹ飬������ģ��ÿһ���ĵ���������next�������������ӶȺ�ƽ�����Ӷȶ����ǳ��������ռ临�Ӷ��½���O(logn)
//����ÿһ����д���ؼ����ڣ�����ÿһ���ڵ㣬��Ҫѭ�����ҵ���ǰ�ڵ���������������һ����ڵ㣬�������м���·�ϵĽڵ�ȫ��ѹ��ջ�С�
class BSTIterator {
public:
	stack<TreeNode*> stk;
	BSTIterator(TreeNode* root) {
		while (root) {
			stk.push(root);
			root = root->left;
		}
	}

	int next() {
		TreeNode* cur = stk.top();
		stk.pop();
		TreeNode* cur_r = cur->right;
		while (cur_r) {
			stk.push(cur_r);
			cur_r = cur_r->left;
		}
		return cur->val;
	}

	bool hasNext() {
		return !stk.empty();
	}
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
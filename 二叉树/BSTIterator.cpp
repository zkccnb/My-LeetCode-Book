#include"TreeNode.h"
//173. 二叉搜索树迭代器
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
//先用中序遍历把所有元素都弄进数组里，再写数组迭代器就好了，想法简单但是空间复杂度是O(n)n为节点个数
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
//用栈代替递归，在树中模拟每一步的迭代操作，next方法的最坏情况复杂度和平均复杂度都不是常数，但空间复杂度下降到O(logn)
//迭代每一步的写法关键在于：对于每一个节点，都要循环地找到当前节点的右子树的最深的一个左节点，并讲这中间链路上的节点全部压入栈中。
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
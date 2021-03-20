#include"TreeNode.h"
//114. 二叉树展开为链表
//这个题在力扣上做的时候可能会造成困惑，因为力扣的主函数并不是直接对root指针进行遍历输出；
//而是对原root指针中的内存单元进行遍历输出！
//这就意味着，我们必须对指针进行“左值解引用”访问，故意篡改内存中的内容，才能在力扣上通过此题
//如果像链表那种避免“左值解引用”的写法则始终不能改变原root指针指向内存中的内容：
//结果就是虽然正确改变了root指针的指向，但原root指针指向的内存值并没变，无法通过此题！
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
//这是第一种写法，非原地算法，时间复杂度：O(n+n)，空间复杂度：O(n)
class Solution {
public:
	vector<TreeNode*> node;
	void flatten(TreeNode* root) {
		preOrder(root);
		if (!node.empty())
		{
			TreeNode* cur = node[0];
			for (int i = 1; i < node.size(); i++) {
				cur->left = nullptr;
				cur->right = node[i];
				cur = cur->right;
			}
		}

	}
	void preOrder(TreeNode* _node) {
		if (_node) node.push_back(_node);
		else return;
		preOrder(_node->left);
		preOrder(_node->right);
	}
};
//这是一种原地算法，时间复杂度:O(n),空间复杂度:O(1)
//依靠找到当前节点的“前驱节点”来一次性地把节点移动到位
//class Solution {
//public:
//	void flatten(TreeNode* root) {
//		TreeNode* cur = root;//当前节点，逐步向右遍历
//		TreeNode* prev;//前驱节点（当前节点左子树中最靠右的节点）
//		while (cur) {
//			if (cur->left)
//			{
//				prev = cur->left;
//				while (prev->right) prev = prev->right;
//				prev->right = cur->right;
//				cur->right = cur->left;
//				cur->left = nullptr;
//			}
//			cur = cur->right;
//		}
//	}
//
//};
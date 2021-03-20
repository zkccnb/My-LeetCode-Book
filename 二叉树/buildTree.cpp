#include"TreeNode.h"
//106. 从中序与后序遍历序列构造二叉树
//和105题一样，注意，必须构造二叉树的数组必须要有中序遍历（只给定前序遍历数组和后序遍历数组不能确定唯一的二叉树！）
//这个题的递归逻辑本质上是前序遍历构造节点
//仔细读读代码里的注释，是这个题的思路步骤
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
		int size = inorder.size();//注意到，两个数组大小是一样的
		if (size == 0) return nullptr;//1. 如果输入数组为空，直接返回空节点
		//2.1 在中序数组中，找后序数组的最后一个值
		auto it_in = find(inorder.begin(), inorder.end(), postorder[size - 1]);
		TreeNode* node = new TreeNode(*it_in);//2.2 用找到的值新建一个节点
		//3. 用找到节点的位置分割中序数组
		vector<int> inorder_l(inorder.begin(), it_in);
		vector<int> inorder_r(it_in + 1, inorder.end());
		//4. 利用中序、后序数组大小必相等样这个性质，去分割后序数组
		vector<int> postorder_l(postorder.begin(), postorder.begin() + inorder_l.size());
		vector<int> postorder_r(postorder.begin() + inorder_l.size(), postorder.end() - 1);
		//5. 剩下的事情交给递归就好了，逻辑上相当于前序遍历
		node->left = build(inorder_l, postorder_l);
		node->right = build(inorder_r, postorder_r);
		//6. 最后别忘了返回节点
		return node;
	}
};
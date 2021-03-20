#include"TreeNode.h"
//101. 对称二叉树
//你的写法使用了递归，但不是常见的任何一种二叉树递归方法
//而且需要考虑的情况比较多，容易出错。
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
	bool flag;
	bool isSymmetric(TreeNode* root) {
		flag = true;
		if (root)
		{
			if (root->left && root->right) return judge(root->left, root->right);
			else if (!root->left && !root->right) return true;
			else return false;
		}
		else return true;
	}
	bool judge(TreeNode* left, TreeNode* right) {
		if (left->left && left->right && right->left && right->right && flag)
		{//4个子节点都不为空
			if (left->left->val == right->right->val && left->right->val == right->left->val && left->val == right->val)
			{//目前对称，向下递归
				flag = judge(left->left, right->right);
				flag = judge(left->right, right->left);
			}
			else return false;//不对称，返回上层，且需要不停地返回上层，直到退出递归栈
		}
		else if (!left->left && left->right && right->left && !right->right && flag)
		{//外侧2个子节点为空
			if (left->right->val == right->left->val && left->val == right->val)
			{//目前对称，向下递归
				//flag = judge(left->left, right->right);
				flag = judge(left->right, right->left);
			}
			else return false;//不对称，返回上层，且需要不停地返回上层，直到退出递归栈
		}
		else if (left->left && !left->right && !right->left && right->right && flag)
		{//内侧2个子节点为空
			if (left->left->val == right->right->val && left->val == right->val)
			{//目前对称，向下递归
				flag = judge(left->left, right->right);
				//flag = judge(left->right, right->left);
			}
			else return false;//不对称，返回上层，且需要不停地返回上层，直到退出递归栈
		}
		else if (!left->left && !left->right && !right->left && !right->right && left->val==right->val && flag)
		{//遍历到底了，且此时仍未出现不对称
			return true;//对称，返回上层，且只返回一层
		}
		else
		{//其他情况一定都是不对称的
			return false;//不对称，返回上层，且需要不停地返回上层，直到退出递归栈
		}
		return flag;//这一句其实可以不加，但是在有些苛刻的编译器上（把所有警告视为错误），不加会报错
		//不加的话会警告：在非void类型函数体中，不是所有的路径都是返回值
	}
};
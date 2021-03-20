#include"TreeNode.h"
//101. �Գƶ�����
//���д��ʹ���˵ݹ飬�����ǳ������κ�һ�ֶ������ݹ鷽��
//������Ҫ���ǵ�����Ƚ϶࣬���׳���
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
		{//4���ӽڵ㶼��Ϊ��
			if (left->left->val == right->right->val && left->right->val == right->left->val && left->val == right->val)
			{//Ŀǰ�Գƣ����µݹ�
				flag = judge(left->left, right->right);
				flag = judge(left->right, right->left);
			}
			else return false;//���Գƣ������ϲ㣬����Ҫ��ͣ�ط����ϲ㣬ֱ���˳��ݹ�ջ
		}
		else if (!left->left && left->right && right->left && !right->right && flag)
		{//���2���ӽڵ�Ϊ��
			if (left->right->val == right->left->val && left->val == right->val)
			{//Ŀǰ�Գƣ����µݹ�
				//flag = judge(left->left, right->right);
				flag = judge(left->right, right->left);
			}
			else return false;//���Գƣ������ϲ㣬����Ҫ��ͣ�ط����ϲ㣬ֱ���˳��ݹ�ջ
		}
		else if (left->left && !left->right && !right->left && right->right && flag)
		{//�ڲ�2���ӽڵ�Ϊ��
			if (left->left->val == right->right->val && left->val == right->val)
			{//Ŀǰ�Գƣ����µݹ�
				flag = judge(left->left, right->right);
				//flag = judge(left->right, right->left);
			}
			else return false;//���Գƣ������ϲ㣬����Ҫ��ͣ�ط����ϲ㣬ֱ���˳��ݹ�ջ
		}
		else if (!left->left && !left->right && !right->left && !right->right && left->val==right->val && flag)
		{//���������ˣ��Ҵ�ʱ��δ���ֲ��Գ�
			return true;//�Գƣ������ϲ㣬��ֻ����һ��
		}
		else
		{//�������һ�����ǲ��ԳƵ�
			return false;//���Գƣ������ϲ㣬����Ҫ��ͣ�ط����ϲ㣬ֱ���˳��ݹ�ջ
		}
		return flag;//��һ����ʵ���Բ��ӣ���������Щ���̵ı������ϣ������о�����Ϊ���󣩣����ӻᱨ��
		//���ӵĻ��ᾯ�棺�ڷ�void���ͺ������У��������е�·�����Ƿ���ֵ
	}
};
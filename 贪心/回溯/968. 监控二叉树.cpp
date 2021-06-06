#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
//很难的一道题，不告诉你根本想不到的。。
//贪心体现在只在左右子节点都没有覆盖的节点上添加摄像头
//因为用后序遍历，从最左边的叶子节点开始向上判断，还要注意对头节点的判断
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
 //返回0：此节点无覆盖
 //返回1：此节点有摄像头
 //返回2：此节点有覆盖
class Solution {
public:
	int ret;
	int minCameraCover(TreeNode* root) {
		ret = 0;
		if (!postOrder(root)) ret++;//头节点还没有覆盖，需要在头节点加一个摄像头
		return ret;
	}
	int postOrder(TreeNode* node) {
		int status_l, status_r;
		if (!node) return 2;//空节点算作有覆盖的节点
		status_l = postOrder(node->left);
		status_r = postOrder(node->right);
		//叶子节点：设置状态为“无覆盖”
		if (status_l == 2 && status_r == 2) return 0;
		//叶子节点上一层的节点：装上摄像头
		if (status_l == 0 || status_r == 0)
		{
			ret++;
			return 1;
		}
		//子节点有一个有摄像头：设置此节点状态为“有覆盖”
		if (status_l == 1 || status_r == 1)
		{
			return 2;
		}
		return 2;//其他情况都认为此节点有覆盖了
	}
};
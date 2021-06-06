#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
//���ѵ�һ���⣬������������벻���ġ���
//̰��������ֻ�������ӽڵ㶼û�и��ǵĽڵ����������ͷ
//��Ϊ�ú��������������ߵ�Ҷ�ӽڵ㿪ʼ�����жϣ���Ҫע���ͷ�ڵ���ж�
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
 //����0���˽ڵ��޸���
 //����1���˽ڵ�������ͷ
 //����2���˽ڵ��и���
class Solution {
public:
	int ret;
	int minCameraCover(TreeNode* root) {
		ret = 0;
		if (!postOrder(root)) ret++;//ͷ�ڵ㻹û�и��ǣ���Ҫ��ͷ�ڵ��һ������ͷ
		return ret;
	}
	int postOrder(TreeNode* node) {
		int status_l, status_r;
		if (!node) return 2;//�սڵ������и��ǵĽڵ�
		status_l = postOrder(node->left);
		status_r = postOrder(node->right);
		//Ҷ�ӽڵ㣺����״̬Ϊ���޸��ǡ�
		if (status_l == 2 && status_r == 2) return 0;
		//Ҷ�ӽڵ���һ��Ľڵ㣺װ������ͷ
		if (status_l == 0 || status_r == 0)
		{
			ret++;
			return 1;
		}
		//�ӽڵ���һ��������ͷ�����ô˽ڵ�״̬Ϊ���и��ǡ�
		if (status_l == 1 || status_r == 1)
		{
			return 2;
		}
		return 2;//�����������Ϊ�˽ڵ��и�����
	}
};
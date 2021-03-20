#include"TreeNode.h"
//449. ���л��ͷ����л�����������
//�������ô˵�أ��ܿ���Դ��밲ȫ�Ե��ƿأ�ϸ������ǳ��࣬����һ��д��
//�ұ���ͽ��붼���˲�����������뻹�ã�����Ĳ��������Ҫʮ��ע�⣺
//��ӵ�Ԫ�ص��õ��ǿ������죬���һ��ʼ������ǿ�ָ��Ļ�����ô֮����Զ����еĿ�ָ����β���������Ӱ�촫��Ŀ�ָ��
//���������ӵ���һ����ָ���ָ������Ͳ�һ���ˣ������ָ��Ͷ����п���һ�ݵ�ָ��ָ��ͬһƬ��ַ�����Ըı������ָ���ֵ���Ըı�һ��ʼ��ӵķǿ�ָ�룡����
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string data;
		if (!root) return data;
		queue<TreeNode*> q;
		TreeNode* front = NULL;
		q.push(root);
		int size = q.size();
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				front = q.front();
				if (front)
				{
					q.push(front->left);
					q.push(front->right);
					data += to_string(front->val);
				}
				else data.push_back('n');
				data.push_back(' ');
				q.pop();
			}
		}
		return data;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) return NULL;
		string buf;
		int index_d = 0;
		while (data[index_d] != ' ') buf += data[index_d++];
		index_d++;
		TreeNode* node = new TreeNode(atoi(buf.c_str()));
		queue<TreeNode*> q;
		TreeNode* front = NULL;
		q.push(node);
		int size_q = q.size();
		buf.clear();
		while (index_d < data.size()) {
			front = q.front();
			q.pop();
			if (!front) continue;
			//�������ӽڵ�
			if (index_d >= data.size()) break;
			while (data[index_d] != ' ') buf += data[index_d++];
			index_d++;
			if (buf == "n") front->left = NULL;
			else front->left = new TreeNode(atoi(buf.c_str()));
			q.push(front->left);
			buf.clear();

			//�������ӽڵ�
			if (index_d >= data.size()) break;
			while (data[index_d] != ' ') buf += data[index_d++];
			index_d++;
			if (buf == "n") front->right= NULL;
			else front->right = new TreeNode(atoi(buf.c_str()));
			q.push(front->right);
			buf.clear();
		}
		return node;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
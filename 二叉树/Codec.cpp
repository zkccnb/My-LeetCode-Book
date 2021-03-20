#include"TreeNode.h"
//449. 序列化和反序列化二叉搜索树
//这个题怎么说呢，很考验对代码安全性的掌控，细节问题非常多，很难一次写对
//我编码和解码都用了层序遍历，编码还好，解码的层序遍历需要十分注意：
//入队的元素调用的是拷贝构造，如果一开始传入的是空指针的话，那么之后你对队列中的空指针如何操作都不会影响传入的空指针
//而如果你入队的是一个有指向的指针情况就不一样了！传入的指针和队列中拷贝一份的指针指向同一片地址，所以改变队列里指针的值可以改变一开始入队的非空指针！！！
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
			//构造左子节点
			if (index_d >= data.size()) break;
			while (data[index_d] != ' ') buf += data[index_d++];
			index_d++;
			if (buf == "n") front->left = NULL;
			else front->left = new TreeNode(atoi(buf.c_str()));
			q.push(front->left);
			buf.clear();

			//构造右子节点
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
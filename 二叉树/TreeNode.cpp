#include"TreeNode.h"

//支持用数组构建一棵树
TreeNode::TreeNode(int* arr, int size) :arrayTree(arr), sizeOfarray(size), val(arr[0]), left(nullptr), right(nullptr){
	preOrderRecur(this->left, 0, true); preOrderRecur(this->right, 0, false);
}

//前序遍历，获取节点个数（如果一层没满，依然按照这一层最多的节点个数去统计）
void TreeNode::preOrderRecur(TreeNode* head) {
	if (head == nullptr) return;
	sizeOfTree++;
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

//前序遍历，用数组构造一棵树
//这里一定要用指针引用，否则只相当于一个“指针拷贝”，最后this指针指向的内存里是啥也没有的。
void TreeNode::preOrderRecur(TreeNode* &head, int num, bool isLeft) {
	if (m_count >= sizeOfarray) return;
	if (isLeft) num = 2 * num + 1;
	else num = 2 * num + 2;
	if (num < sizeOfarray)
	{
		if (arrayTree[num] != null) head = new TreeNode(arrayTree[num]);
		else { head = nullptr; return; }
	}
	else return;
	m_count++;
	if (head)
	{
		preOrderRecur(head->left, num, true);
		preOrderRecur(head->right, num, false);
	}
	else { return; }
}

//输出指定二叉树
ostream& operator<<(ostream& os, TreeNode* root)
{
	queue<TreeNode*> qN;
	if (root) qN.push(root);
	else { os << "树根没了！"; return os; }
	size_t count = 0;
	size_t size = root->getSize();
	while (count < size) {
		int size = qN.size();
		for (int i = 0; i < size; i++) {
			if (qN.front()) { os << qN.front()->val << ' '; count++; }
			else { os << 'n' << ' '; qN.pop(); continue; }
			if (qN.front()->left) qN.push(qN.front()->left);
			else qN.push(nullptr);
			if (qN.front()->right) qN.push(qN.front()->right);
			else qN.push(nullptr);
			qN.pop();
		}
		os << "\n";
	}
	return os;
}
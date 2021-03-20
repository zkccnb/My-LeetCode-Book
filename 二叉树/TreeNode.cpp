#include"TreeNode.h"

//֧�������鹹��һ����
TreeNode::TreeNode(int* arr, int size) :arrayTree(arr), sizeOfarray(size), val(arr[0]), left(nullptr), right(nullptr){
	preOrderRecur(this->left, 0, true); preOrderRecur(this->right, 0, false);
}

//ǰ���������ȡ�ڵ���������һ��û������Ȼ������һ�����Ľڵ����ȥͳ�ƣ�
void TreeNode::preOrderRecur(TreeNode* head) {
	if (head == nullptr) return;
	sizeOfTree++;
	preOrderRecur(head->left);
	preOrderRecur(head->right);
}

//ǰ������������鹹��һ����
//����һ��Ҫ��ָ�����ã�����ֻ�൱��һ����ָ�뿽���������thisָ��ָ����ڴ�����ɶҲû�еġ�
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

//���ָ��������
ostream& operator<<(ostream& os, TreeNode* root)
{
	queue<TreeNode*> qN;
	if (root) qN.push(root);
	else { os << "����û�ˣ�"; return os; }
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
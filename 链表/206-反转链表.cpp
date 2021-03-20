#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	//输出指定链表
	friend ostream& operator<<(ostream& os, ListNode* &theList)
	{
		ListNode* thisNode = theList;
		while (thisNode != nullptr)
		{
			os << thisNode->val << " ";
			thisNode = thisNode->next;
		}
		return os;
	}
};
class Solution {
public:
	//错误的写法
	/*ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		auto thisNode = head->next;
		auto tempNode = head;
		auto retL = head;
		retL->next = nullptr;
		while (thisNode)
		{
			tempNode = retL;
			retL = thisNode;
			retL->next = tempNode;
			thisNode = thisNode->next;
		}
		return retL;
	}*/
	//正确的写法
	//当解引用作为左值时，需要额外谨慎，必要时先把解引用的右值保存下来
	ListNode* reverseList(ListNode* head) {
		ListNode* retL = nullptr;
		auto thisNode = head;
		ListNode* temp = nullptr;
		while (thisNode)
		{
			temp = thisNode->next;//把下一个本节点保存下来，只有这样才不会丢失
			thisNode->next = retL;
			retL = thisNode;
			thisNode = temp;
		}
		return retL;
	}

	//将数组中的元素依次添加进链表
	ListNode* setList(int* arr, int num)
	{
		ListNode* theList = new ListNode(arr[0]);
		ListNode* thisNode = theList;
		for (auto i = 1; i != num; i++)
		{
			thisNode->next = new ListNode();
			thisNode = thisNode->next;
			thisNode->val = arr[i];
			thisNode->next = nullptr;
		}
		return theList;
	}
	//设置环形链表
	ListNode* setCirList(int* arr, int num, int cir)
	{
		ListNode* theList = new ListNode(arr[0]);
		ListNode* thisNode = theList;
		ListNode* cirNode = nullptr;
		for (auto i = 1; i != num; i++)
		{
			thisNode->next = new ListNode();
			thisNode = thisNode->next;
			thisNode->val = arr[i];
			thisNode->next = nullptr;
			if (i == cir) cirNode = thisNode;
		}
		thisNode->next = cirNode;
		return theList;
	}
};
int main() {
	int a[5] = { 1,2,3,4,5 };
	int b[4] = { 1,2,3,4 };
	Solution s;
	ListNode* l1 = s.setList(a, sizeof(a) / 4);
	ListNode* L1 = s.reverseList(l1);
	cout << L1 << endl;
}
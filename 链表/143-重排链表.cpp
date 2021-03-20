#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	//输出指定链表
	//friend ostream& operator<<(ostream& os, ListNode* theList)
	//{
	//	ListNode* thisNode = theList;
	//	while (thisNode != nullptr)
	//	{
	//		os << thisNode->val << " ";
	//		thisNode = thisNode->next;
	//	}
	//	//theList = thisNode;
	//	return os;
	//}
};
ostream& operator<<(ostream& os, ListNode* theList)
{
	ListNode* thisNode = theList;
	while (theList != nullptr)
	{
		os << theList->val << " ";
		theList = theList->next;
	}
	theList = thisNode;
	return os;
}
//ostream & operator<<(ostream&os, ListNode* &theList) {
//	while (theList) {
//		os << theList->val << " ";
//		theList = theList->next;
//	}
//	return os;
//}
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		{
			return;
		}
		auto fast = head;
		auto preNode = head;
		auto slow = head;

		while (slow->next)
		{
			//找到最后一个节点
			while (fast->next)
			{
				if (fast->next->next == nullptr) preNode = fast;
				fast = fast->next;
			}
			if (slow->next != fast)
			{
				//把最后一个节点移到指定的节点
				fast->next = slow->next;
				preNode->next = nullptr;
				slow->next = fast;
			}
			else return;
			fast = head;
			slow = slow->next->next;
		}
	}
	void reorderList_2(ListNode* head) {
		//if (!head || !head->next) return;
		auto midNode = middleNode(head);
		midNode = reverseList(midNode);
		auto tempMid = midNode;
		auto tempHead = head;
		while (midNode->next)
		{
			tempMid = midNode->next;
			midNode->next = tempHead->next;
			tempHead->next = midNode;
			midNode = tempMid;
			tempHead = tempHead->next->next;
		}

	}
	ListNode* middleNode(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next)
		{
			if (fast->next->next) fast = fast->next->next;
			else fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
	ListNode* reverseList(ListNode* head) {
		ListNode* retL = nullptr;
		auto thisNode = head;
		ListNode* temp = nullptr;
		while (thisNode)
		{
			temp = thisNode->next;
			thisNode->next = retL;
			retL = thisNode;
			thisNode = temp;
		}
		return retL;
	}
	////将数组中的元素依次添加进链表
	//ListNode* setList(int* arr, int num)
	//{
	//	ListNode* theList = new ListNode(arr[0]);
	//	ListNode* thisNode = theList;
	//	for (auto i = 1; i != num; i++)
	//	{
	//		thisNode->next = new ListNode();
	//		thisNode = thisNode->next;
	//		thisNode->val = arr[i];
	//		thisNode->next = nullptr;
	//	}
	//	return theList;
	//}
	ListNode* setList(int* arr, int num) {
		ListNode* theList = new ListNode(arr[0]);
		ListNode* thisList = theList;
		for (int i = 1; i < num; i++) {
			thisList->next = new ListNode(arr[i]);
			thisList = thisList->next;
		}
		return theList;
	}
};
int main() {
	int a[5] = { 1,2,3,4,5 };
	Solution s;
	ListNode* l1 = s.setList(a, sizeof(a) / 4);
	//s.reorderList_2(l1);
	cout << l1 << endl;
	cout << l1 << endl;
}
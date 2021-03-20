
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* firstPtr = head;
		ListNode* secondPtr = head;
		if (firstPtr->next == nullptr) return nullptr;
		//头指针先走
		for (int i = n; i != -1; i--)
		{
			if (firstPtr == nullptr) return head->next;
			firstPtr = firstPtr->next;
		}
		while (firstPtr != nullptr)
		{
			firstPtr = firstPtr->next;
			secondPtr = secondPtr->next;
		}
		secondPtr->next = secondPtr->next->next;
		return head;
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
};
int main() {
	int a[5] = { 1,2,3,4,5 };
	Solution s;
	ListNode* l1 = s.setList(a, sizeof(a) / 4);
	ListNode* l = s.removeNthFromEnd(l1, 2);
	cout << l << endl;
}
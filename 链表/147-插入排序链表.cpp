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
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummyNode = new ListNode(-1);
		//dummyNode->next = head;
		auto curr = head;
		auto prev = dummyNode;
		//auto preCurr = dummyNode;//没必要了
		while (curr)
		{
			while (prev->next && prev->next->val < curr->val) prev = prev->next;
			auto cn = curr->next;//1
			curr->next = prev->next;//2
			prev->next = curr;//3
			curr = cn;//4
			prev = dummyNode;
		}

		return dummyNode->next;
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
	int a[5] = { 1,5,2,4,3 };
	Solution s;
	ListNode* l1 = s.setList(a, sizeof(a) / 4);
	ListNode* l = s.insertionSortList(l1);
	cout << l << endl;
}
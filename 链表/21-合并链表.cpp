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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		auto next_l1 = l1;
		auto next_l2 = l2;
		auto retL = l1;
		while (l2)
		{
			if (l1) next_l1 = l1->next;
			next_l2 = l2->next;
			//l2插入l1后面
			if (l2->val >= l1->val)
			{
				l2->next = l1->next;
				l1->next = l2;
			}
			else//l2插入到l1前面
			{
				l2->next = l1;
				l1 = l2;
			}
			l1 = next_l1;
			l2 = next_l2;
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
};
int main() {
	int a[5] = { 1,2,3,4,5 };
	int b[4] = { -1,1,6,8 };
	Solution s;
	ListNode* l1 = s.setList(a, sizeof(a) / 4);
	ListNode* l2 = s.setList(b, sizeof(b) / 4);
	ListNode* l=s.mergeTwoLists(l1,l2);
	cout << l << endl;
}
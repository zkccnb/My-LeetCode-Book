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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		ListNode* dummyNode = new ListNode(-1);
		auto prev = dummyNode;
		auto mark = dummyNode;
		auto hn = head;
		int index = 1;
		while (head)
		{
			hn = head->next;
			head->next = nullptr;
			if (index < m)
			{
				prev->next = head;
				mark = mark->next;
				prev = prev->next;
			}
			else if (index >= m && index <= n)
			{
				head->next = mark->next;
				mark->next = head;
			}
			else if (index == n + 1)
			{
				for (auto i = m; i < n + 1; i++) prev = prev->next;
				prev->next = head;
			}
			else
			{
				prev = prev->next;
				prev->next = head;
			}
			head = hn;
			index++;
		}
		return dummyNode->next;
	}
	//将数组中的元素依次添加进链表
	ListNode* setList(int* arr, int num)
	{
		ListNode* dummyNode = new ListNode(-1);
		auto prev = dummyNode;
		for (auto i = 0; i != num; i++)
		{
			prev->next = new ListNode(arr[i]);
			prev = prev->next;
		}
		return dummyNode->next;
	}
	//把一个链表拷贝到另一个链表中（深拷贝）
	//这里把head中的元素一个一个的复制过去
	//也是LeetCode中链表题的一种常见解法
	//最基本的套路
	ListNode* copyList(ListNode* head)
	{
		ListNode* dummyNode = new ListNode(-1);
		auto prev = dummyNode;
		auto hn = head;
		while (head)
		{
			hn = head->next;
			head->next = nullptr;
			prev->next = head;
			head = hn;
			prev = prev->next;
		}
		return dummyNode->next;
	}
};
int main() {
	int a[5] = { 1,2,3,4,5 };
	Solution s;
	ListNode* l1 = s.setList(a, sizeof(a) / 4);
	//ListNode* l = s.reverseBetween(l1,1,5);
	ListNode* l = s.copyList(l1);
	cout << l << endl;
}
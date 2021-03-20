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
	//时间复杂度O(n)，空间复杂度O(1),双指针
	ListNode* middleNode_fast_slow(ListNode* head) {
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
	//时间复杂度O(n2)，空间复杂度O(1)，原地扫描
	//（可见原地扫描的时间效率都不太高啊。。。除非用到链表插入可能会快点）
	ListNode* middleNode_traversal(ListNode* head) {
		auto thisNode = head;
		auto detectNode = thisNode;
		size_t step = 0;
		while (thisNode)//总共执行n/2次
		{
			detectNode = thisNode;
			for (auto i = 0; i < step; i++)//每轮执行n/2
			{
				detectNode = detectNode->next;
				if (!detectNode) return thisNode;
			}
			if (!detectNode->next) return thisNode;
			thisNode = thisNode->next;
			step++;
		}
		return thisNode;
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
	ListNode* l2 = s.setList(b, sizeof(b) / 4);
	ListNode* L1 = s.middleNode_fast_slow(l1);
	ListNode* L2 = s.middleNode_traversal(l2);
	cout << L1 << endl;
	cout << L2 << endl;
}
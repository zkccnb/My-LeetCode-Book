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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		bool addFlag = false;
		ListNode* retL = new ListNode(0);
		ListNode* thisNode = retL;
		while (l1 != nullptr || l2 != nullptr)
		{
			thisNode->val = l1->val + l2->val + addFlag;
			if (thisNode->val >= 10)
			{
				thisNode->val %= 10;
				addFlag = true;
			}
			else addFlag = false;
			l1 = l1->next;
			l2 = l2->next;
			//需要补零的情况1
			if (l1 == nullptr && l2 != nullptr)
			{
				l1 = new ListNode(0);
				thisNode->next = new ListNode(0);
			}
			//需要补零的情况2
			else if (l2 == nullptr && l1 != nullptr)
			{
				l2 = new ListNode(0);
				thisNode->next = new ListNode(0);
			}
			//需要补零的情况3
			else if (l1 == nullptr && l2 == nullptr && addFlag == true)
			{
				l1 = new ListNode(0);
				l2 = new ListNode(0);
				thisNode->next = new ListNode(0);
			}
			//不需要补零的情况，但还需要继续往下算
			else if (l1 != nullptr && l2 != nullptr)
			{
				thisNode->next = new ListNode(0);
			}
			//不需要补零，也不需要继续往下算
			else if (l1 == nullptr && l2 == nullptr && addFlag == false)
			{
				break;
			}
			thisNode = thisNode->next;
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
	int a[7] = { 9,9,9,9,9,9,9 };
	int b[4] = { 9,9,9,9 };
	Solution s;
	ListNode* l1 = s.setList(a, sizeof(a) / 4);
	ListNode* l2 = s.setList(b, sizeof(b) / 4);
	ListNode* l = s.addTwoNumbers(l1, l2);
	cout << l << endl;
}
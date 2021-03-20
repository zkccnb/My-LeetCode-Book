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
		while (theList != nullptr)
		{
			os << theList->val << " ";
			theList = theList->next;
		}
		theList = thisNode;
		return os;
	}
};
class Solution {
public:
	//你的方法：空间复杂度为O(1),时间复杂度为O(n2)：
	//因为你的快慢指针都走了不止一趟

	//答案中的方法可以实现 时间复杂度O(n)，空间复杂度O(1)。
	//答案也是快慢指针，但不用每次都从头走，两个指针走一次就行。
	//如果有环，快指针迟早会套慢指针一圈，快指针走的速度始终是慢指针的2倍，
	//如此，找到环首只是一个小学数学问题
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr) return nullptr;

		size_t index = 0;//第index节点处有环
		size_t circle_size = 1;//环的大小
		auto firptr = head;
		auto secptr = head;
		auto lastfir = head;

		while (firptr != nullptr)
		{
			lastfir = firptr;
			secptr = head;//每次把慢指针位置归零
			//快指针走index+circle步 慢指针走index步
			for (auto i = 0; i != index; i++) secptr = secptr->next;			
			for (auto i = 0; i != index + circle_size; i++)
			{
				firptr = firptr->next;
				//有指针为空：说明没环
				if (firptr == nullptr || secptr == nullptr) return nullptr;
				//快慢指针重合：说明此处就是环首
				else if (firptr == secptr) return secptr;
				//本次快指针与上次快指针位置重合：说明有环，但慢指针走的步数不对，找不到环首
				else if (firptr == lastfir)
				{
					index++;
					break;
				}
			}
			//快指针走完了index+circle步，仍然不为空，不与快指针重合，不与上次快指针位置重合：
			//说明环数小了，探测不出，加大环数
			circle_size++;
		}
		return nullptr;
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
	Solution s;
	ListNode* l1 = s.setCirList(a, sizeof(a) / 4, 3);
	ListNode* l = s.detectCycle(l1);
	cout << l << endl;
	cout << l1 << endl;
}
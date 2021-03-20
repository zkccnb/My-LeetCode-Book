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
	//原地重排，实现奇偶链表
	ListNode* oddEvenList(ListNode* head) {
		//链表不为空
		if (head != nullptr)
		{
			//链表只有1个或2个元素，不需重排
			if (head->next == nullptr || head->next->next == nullptr) return head;
			ListNode* OddNode = head->next->next;//当前最靠左的奇数节点
			ListNode* NextOddNode = nullptr;//下一个奇数节点
			ListNode* currentNode = head;//当前节点
			ListNode* nextNode;//当前节点的下一个节点，用于插入
			ListNode* preOddNode = head->next;//当前奇数节点的前节点
			ListNode* NextpreOddNode = nullptr;//下一轮的奇数前节点
			while (OddNode != nullptr)
			{
				if (OddNode->next != nullptr&&OddNode->next->next != nullptr)
				{
					NextOddNode = OddNode->next->next;//找下一个奇数节点
				}
				else { NextOddNode = nullptr; }
				NextpreOddNode = OddNode->next;
				nextNode = currentNode->next;

				//在当前节点后面插入奇数节点
				currentNode->next = OddNode;
				preOddNode->next = OddNode->next;
				OddNode->next = nextNode;
				//向后移动节点
				currentNode = currentNode->next;
				preOddNode = NextpreOddNode;
				OddNode = NextOddNode;
			}
			return head;
		}
		//链表为空，返回空指针
		else return nullptr;

	}
	//将数组中的元素依次添加进链表
	ListNode* setList(int* arr, int num)
	{
		ListNode* theList=new ListNode(arr[0]);
		ListNode* thisNode = theList;
		for (auto i = 1; i != num; i++)
		{
		    thisNode->next=new ListNode();
			thisNode = thisNode->next;
			thisNode->val=arr[i];
			//thisNode = theList;
		}
		m_size = num;
		return theList;
	}
private:
	size_t m_size;//链表长度

};
int main() {
	int a[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
	Solution s;
	ListNode* initNode = s.setList(a,sizeof(a)/4);//临时对象
	cout << initNode << endl;
	ListNode* retNode = s.oddEvenList(initNode);
	cout << retNode << endl;
}

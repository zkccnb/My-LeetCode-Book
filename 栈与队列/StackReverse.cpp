#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

//用递归实现仅用一个堆栈弹出栈底元素
//static全局变量运行完内存释放，递归static方法，进建立一次方法
//静态变量用new建立
static int getAndRemoveLastElement(stack<int>& stack) {
	int result = stack.top();//返回当前顶层元素
	queue<int> q;
	q.
	stack.pop();//弹出
	if (stack.empty()) {//弹出后为空
		return result;//返回倒数第一个元素
	}
	else
	{
		int last = getAndRemoveLastElement(stack);//获取最后一个元素
		stack.push(result);//压入从倒数第二个元素开始元素
		return last;//始终返回堆栈最后一个元素
	}
}

static void reverse(stack<int>& stack) {
	if (stack.empty())  //递归结束
		return;
	int i = getAndRemoveLastElement(stack);//弹出底层元素
	reverse(stack);
	stack.push(i);//倒着即从顶向下压入
}

int main() {
	int arr[] = { 1,3,5,7,9,2,4,6,8 };
	stack<int> stack;
	for (int i = 0; i < 9; i++) {
		stack.push(arr[i]);
	}

	//顺序测试
	/*for (int t = 0; t < 9; t++) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;*/

	//反转测试
	reverse(stack);
	for (int u = 0; u < 9; u++) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	system("pause");
}


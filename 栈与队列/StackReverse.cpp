#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

//�õݹ�ʵ�ֽ���һ����ջ����ջ��Ԫ��
//staticȫ�ֱ����������ڴ��ͷţ��ݹ�static������������һ�η���
//��̬������new����
static int getAndRemoveLastElement(stack<int>& stack) {
	int result = stack.top();//���ص�ǰ����Ԫ��
	queue<int> q;
	q.
	stack.pop();//����
	if (stack.empty()) {//������Ϊ��
		return result;//���ص�����һ��Ԫ��
	}
	else
	{
		int last = getAndRemoveLastElement(stack);//��ȡ���һ��Ԫ��
		stack.push(result);//ѹ��ӵ����ڶ���Ԫ�ؿ�ʼԪ��
		return last;//ʼ�շ��ض�ջ���һ��Ԫ��
	}
}

static void reverse(stack<int>& stack) {
	if (stack.empty())  //�ݹ����
		return;
	int i = getAndRemoveLastElement(stack);//�����ײ�Ԫ��
	reverse(stack);
	stack.push(i);//���ż��Ӷ�����ѹ��
}

int main() {
	int arr[] = { 1,3,5,7,9,2,4,6,8 };
	stack<int> stack;
	for (int i = 0; i < 9; i++) {
		stack.push(arr[i]);
	}

	//˳�����
	/*for (int t = 0; t < 9; t++) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;*/

	//��ת����
	reverse(stack);
	for (int u = 0; u < 9; u++) {
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	system("pause");
}


#include<iostream>
using namespace std;
//��̬�滮�ľ���������Ŀ���ܼ򵥣���Ҫ����˼�룺
//1. ȷ��dp���������
//2. ȷ���ݹ�ʽ
//3. dp����ĳ�ֵ
//4. ��α�����
//5. �����Ƶ���дд
class Solution {
public:
	int fib(int n) {
		if (n < 2) return n;
		int dp[2] = { 0,1 };//dp�����ֵ
		int next = 0;
		//forѭ���еľ��Ǳ����ó�dp����ķ��������ַ�ʽ�����˵ݹ飬һ��ʼ��̫���룩
		for (int i = 2; i <= n; i++) {
			next = dp[0] + dp[1];//�ݹ�ʽ
			dp[0] = dp[1];
			dp[1] = next;
		}
		return next;
	}
};
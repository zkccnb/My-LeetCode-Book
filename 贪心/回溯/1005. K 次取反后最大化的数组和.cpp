#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//��򵥵��뷨����ÿһ�����ҵ�ǰֵ��С��Ԫ�ظı�����������ʱ�临�Ӷ���O(K*n)+O(n)��Ч�������
class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		for (int i = 0; i < K; i++) {
			int min_i = getMin(A);
			A[min_i] = -A[min_i];
		}
		int sum = 0;
		for (auto r_A : A) {
			sum += r_A;
		}
		return sum;
	}
	int getMin(vector<int>& A) {
		int min = 0;
		for (int i = 0; i < A.size(); i++) {
			min = A[min] > A[i] ? i : min;
		}
		return min;
	}
};
//���ַ�����ʱ�临�Ӷ��ǣ�O(sort)+O(K)+O(n)�����ַ���ֻ��˵�ǳ��������뵽������ʱ�临�Ӷ�Ҳû�кܵͣ���������ķ����ͺܶ��ˣ�
//class Solution {
//public:
//	int largestSumAfterKNegations(vector<int>& A, int K) {
//		sort(A.begin(), A.end(), [](int a, int b) {return abs(a) > abs(b); });//1. ������ֵ��С��������
//		for (int i = 0; i < A.size(); i++) {//2. ����ߵ�����ʼ���Ѹ�����ת��ֱ��K�Ĵ�������Ϊֹ
//			if (K > 0 && A[i] < 0)
//			{
//				A[i] *= -1;
//				K--;
//			}
//		}
//		while (K--) A[A.size() - 1] *= -1;//3. ���K�Ĵ�����û���꣬�Ͱ����ұߵ���������ת��ֱ����������
//		int sum = 0;
//		for (auto r_A : A) {
//			sum += r_A;
//		}
//		return sum;
//	}
//};
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//最简单的想法就是每一步都找当前值最小的元素改变其正负，但时间复杂度是O(K*n)+O(n)，效果很糟糕
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
//这种方法的时间复杂度是：O(sort)+O(K)+O(n)。这种方法只能说非常不容易想到，而且时间复杂度也没有很低（但比上面的方法低很多了）
//class Solution {
//public:
//	int largestSumAfterKNegations(vector<int>& A, int K) {
//		sort(A.begin(), A.end(), [](int a, int b) {return abs(a) > abs(b); });//1. 按绝对值从小到大排序
//		for (int i = 0; i < A.size(); i++) {//2. 从左边的数开始，把负数反转，直到K的次数用完为止
//			if (K > 0 && A[i] < 0)
//			{
//				A[i] *= -1;
//				K--;
//			}
//		}
//		while (K--) A[A.size() - 1] *= -1;//3. 如果K的次数还没用完，就把最右边的数反复反转，直到次数用完
//		int sum = 0;
//		for (auto r_A : A) {
//			sum += r_A;
//		}
//		return sum;
//	}
//};
#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//˫ָ�룬һǰһ���������Ҳ�ǣ���һ���������������뵽�ģ���ǰ��һ���ɡ�����
class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int left = 0;
		int right = n - 1;
		int maxSum, sum = 0;
		while (left != right) {
			sum = min(height[left], height[right])*(right - left);
			if (height[left] >= height[right]) right--;
			else left++;
			maxSum = max(maxSum, sum);
		}
		return maxSum;
	}
};
int main() {
	vector<int> vec = { 1,8,6,2,5,4,8,3,7 };
	int ret = Solution().maxArea( vec);
	cout << ret << endl;
}
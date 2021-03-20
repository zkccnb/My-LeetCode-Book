#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//和剑指offer那个右旋字符串很像，3次反转解决；这也是这类问题中最快的方法
//但要注意对k取余，应对k>数组长度的情况
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int i = k % nums.size();
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + i);
		reverse(nums.begin() + i, nums.end());
	}
};
int main() {
	vector<int> nums = { 1,2,3,4,5,6,7 };
	Solution().rotate(nums,3);
	for (auto i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}
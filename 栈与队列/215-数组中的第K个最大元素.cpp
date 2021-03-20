#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pri_q;//小根堆，内置仿函数
		for (const auto num : nums)
		{
			pri_q.push(num);
			if (pri_q.size() > k) pri_q.pop();
		}
		return pri_q.top();
	}
};
int main()
{
	vector<int> nums = { 1,2,3,4,5 };
	int ret = Solution().findKthLargest(nums, 2);
	/*for (auto it = ret.cbegin(); it != ret.cend(); it++)
	{
		cout << *it << ' ';
	}*/
	cout <<ret<< endl;
}
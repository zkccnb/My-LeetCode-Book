#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int slow = 0;
		int fast;
		int n = nums.size();
		int sum = 0;
		int minLengthOfWindow = n + 1;//滑动窗口最小长度历史最大值
		for (fast = 0; fast < n; fast++) {
			sum += nums[fast];
			while (sum >= s) {
				minLengthOfWindow = minLengthOfWindow < (fast - slow + 1) ? minLengthOfWindow : (fast - slow + 1);
				if (sum > s) sum -= nums[slow++];
				else break;
			}

		}
		return minLengthOfWindow == n + 1 ? 0 : minLengthOfWindow;
	}
};
int main() {
	vector<int> vec = { 2,3,4,5,8,2,1,6 };
	int ret = Solution().minSubArrayLen(7,vec);
	cout << ret << endl;
}
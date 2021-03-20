#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//二分法，看似简单，但写起来还是有一定技巧的！
//建议多思考cral是怎么写二分法的；总结一下，灵活运用，化为己有！
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int frontIndex = 0;
		int midIndex = frontIndex;
		int backIndex = nums.size() - 1;
		while (frontIndex<=backIndex)
		{
			midIndex = frontIndex + (backIndex - frontIndex) / 2;
			if (nums[midIndex] > target) backIndex = midIndex-1 ;//二分前移
			else if (nums[midIndex] < target) frontIndex = midIndex+1;//二分后移
			else return midIndex;
		}
		return backIndex+1;
	}
};
//这里的处理同样非常巧妙，由于搜索区间是[front,back]（左闭右闭）
		//当front==back时，仍然在搜索区间内，所以应该写在循环里
//下面是你最开始的写法，尽管也对，但是很麻烦。。
//原因在于：cral的写法是每次都移动搜索区间，而你是固定了搜索区间。
//移动搜索区间的好处在于：可以使每一步移动中间索引的操作都不变。
//而如果区间索引固定，中间索引的操作会根据不同情况而变化，造成了需要不断处理边界情况的困局。
//class Solution {
//public:
//	int searchInsert(vector<int>& nums, int target) {
//		int frontIndex = 0;
//		int midIndex = nums.size() / 2 - 1;
//		int backIndex = nums.size() - 1;
//		while (midIndex != frontIndex && midIndex != backIndex) {
//			if (nums[midIndex] == target) return midIndex;
//			else if (nums[midIndex]<target && nums[midIndex + 1]>target) return midIndex + 1;
//			else if (nums[midIndex - 1]<target && nums[midIndex]>target) return midIndex;
//			else {
//				if (nums[midIndex] < target && midIndex != backIndex - 1) midIndex += (backIndex - midIndex) / 2;//二分后移
//				else if (nums[midIndex] > target && midIndex != frontIndex + 1) midIndex -= (midIndex - frontIndex) / 2;//二分前移
//				else if (midIndex == backIndex - 1) return backIndex + 1;
//				else if (midIndex == frontIndex + 1) return frontIndex;
//			}
//		}
//		return -1;
//	}
//};
int main() {
	vector<int> vec = { 1 };
	int ret = Solution().searchInsert(vec, 8);
	cout << ret << endl;
}
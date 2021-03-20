#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//这题不难，关键是要读懂题目的隐含条件，旋转排序数组意味着数组中含有两个升序排序的数组，找到其中可能含有target的升序数组并二分查找就行了
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int front = 0, back = nums.size() - 1;
		int mid = front;
		//先找一下二分查找的头尾
		while (back > front) {
			if (nums[front] == target) return front;
			else if (nums[back] == target) return back;
			if (nums[front] < nums[front + 1]) front++;
			else { front++; break; }
			if (nums[back] > nums[back - 1]) back--;
			else { back--; break; }
		}
		//二分查找
		while (front <= back) {
			mid = (front + back) / 2;
			if (nums[mid] > target) back = mid - 1;
			else if (nums[mid] < target) front = mid + 1;
			else return mid;
		}
		return -1;
	}
};
int main() {
	vector<int> vec = { 1 };
	int ret = Solution().search(vec, 8);
	cout << ret << endl;
}
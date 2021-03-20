#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//���ⲻ�ѣ��ؼ���Ҫ������Ŀ��������������ת����������ζ�������к�������������������飬�ҵ����п��ܺ���target���������鲢���ֲ��Ҿ�����
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int front = 0, back = nums.size() - 1;
		int mid = front;
		//����һ�¶��ֲ��ҵ�ͷβ
		while (back > front) {
			if (nums[front] == target) return front;
			else if (nums[back] == target) return back;
			if (nums[front] < nums[front + 1]) front++;
			else { front++; break; }
			if (nums[back] > nums[back - 1]) back--;
			else { back--; break; }
		}
		//���ֲ���
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
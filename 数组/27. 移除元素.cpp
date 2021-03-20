#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//nums������Ԫ�ص�˳������ν��ֻҪ���еĶ��оͿ���
//˫ָ��ⷨ���������뵽����һ��������Ҳ����������������˫ָ���˼�뻹��Ҫ�������ա�����ͨ��
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		int slow = 0;
		int fast = 0;
		for (fast = 0; fast < n; fast++) {
			if (nums[fast] == val) { continue; }
			else { nums[slow] = nums[fast]; slow++; }
		}
		for (auto i = 0; i < n - slow; i++) {
			nums.pop_back();
		}
		return nums.size();
	}
};
int main() {
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	int size=Solution().removeElement(nums, 2);
	for (auto i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}
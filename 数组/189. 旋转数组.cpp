#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//�ͽ�ָoffer�Ǹ������ַ�������3�η�ת�������Ҳ���������������ķ���
//��Ҫע���kȡ�࣬Ӧ��k>���鳤�ȵ����
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
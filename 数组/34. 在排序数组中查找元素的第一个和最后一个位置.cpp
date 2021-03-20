#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//���ֲ�����Ϊһ�ֶ������Ӷ��㷨�������б�Ҫ�ú��������õġ������һЩϸ�ڴ����Ե÷ǳ��������͸
//�ǵÿ������������ղص�һƪ��⻹����
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left=0,first = 0;
		int right = nums.size() - 1;
		int mid = right / 2;
		while (left <= right) {
			mid = (left + right) / 2;
			if (nums[mid] >=target) { right = mid - 1; }//������mid����ͷ��
			else { left = mid + 1; }
		}
		//����жϺ���Ҫ��һ����˵���ֲ��ҵĽ����mid������Ҳ������
		if (left != nums.size() && nums[left] == target) first = left;
		else first = mid;
		if (first >=0 && first <nums.size() && nums[first]==target)
		{
			left =right= first;
			while (right < nums.size() && nums[right] == target) {
				right++;
			}
			return { left,right-1 };
		}
		else return { -1,-1 };
	}
};
//class Solution {
//public:
//	vector<int> searchRange(vector<int>& nums, int target) {
//		int left = 0;
//		int right = nums.size() - 1;
//		int mid = right / 2;
//		while (left <= right) {
//			mid = (left + right) / 2;
//			if (nums[mid] > target) { right = mid - 1; }
//			else if (nums[mid] < target) { left = mid + 1; }
//			else {
//				left = right = mid;
//				while ((left >= 0 || right < nums.size()) && (nums[left] == target || nums[right] == target)) {
//					if (left >= 0 && nums[left] == target) left--;
//					if (right < nums.size() && nums[right] == target) right++;
//				}
//				return { left + 1,right - 1 };
//			}
//		}
//		return { -1,-1 };
//	}
//};
int main() {
	//vector<int> vec = { 5,5};
	//vector<int> vec = { 1,2,3,4,5,5,5,5,5,5,5,5,5,5,6,7,8,9 };
	//vector<int> vec = { 5 };
	//vector<int> vec = {  };
	//vector<int> vec = { 1,2,5,5,7};
	vector<int> vec = { 1,5,9 };
	vector<int> ret = Solution().searchRange(vec, 5);
	for(auto i=0;i<ret.size();i++) cout << ret[i]<<' ';
	cout << endl;
}
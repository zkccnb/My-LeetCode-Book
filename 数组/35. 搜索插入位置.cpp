#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//���ַ������Ƽ򵥣���д����������һ�����ɵģ�
//�����˼��cral����ôд���ַ��ģ��ܽ�һ�£�������ã���Ϊ���У�
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int frontIndex = 0;
		int midIndex = frontIndex;
		int backIndex = nums.size() - 1;
		while (frontIndex<=backIndex)
		{
			midIndex = frontIndex + (backIndex - frontIndex) / 2;
			if (nums[midIndex] > target) backIndex = midIndex-1 ;//����ǰ��
			else if (nums[midIndex] < target) frontIndex = midIndex+1;//���ֺ���
			else return midIndex;
		}
		return backIndex+1;
	}
};
//����Ĵ���ͬ���ǳ������������������[front,back]������ұգ�
		//��front==backʱ����Ȼ�����������ڣ�����Ӧ��д��ѭ����
//���������ʼ��д��������Ҳ�ԣ����Ǻ��鷳����
//ԭ�����ڣ�cral��д����ÿ�ζ��ƶ��������䣬�����ǹ̶����������䡣
//�ƶ���������ĺô����ڣ�����ʹÿһ���ƶ��м������Ĳ��������䡣
//��������������̶����м������Ĳ�������ݲ�ͬ������仯���������Ҫ���ϴ���߽���������֡�
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
//				if (nums[midIndex] < target && midIndex != backIndex - 1) midIndex += (backIndex - midIndex) / 2;//���ֺ���
//				else if (nums[midIndex] > target && midIndex != frontIndex + 1) midIndex -= (midIndex - frontIndex) / 2;//����ǰ��
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
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;//first存元素值，second存下标值
		for (auto i = 0; i != nums.size(); i++)
		{
			auto it = hash.find(target - nums[i]);
			if (it != hash.end()) return { it->second,i };//找到了，返回
			else hash[nums[i]] = i;//找不到，把当前值放入表
		}
		return {};//遍历结束，还没找到，说明没有
	}
};
int main()
{
	vector<int> a = { 1,2,3,4 };
	Solution s;
	vector<int> vec = s.twoSum(a,5);
	for(auto it=vec.cbegin();it!=vec.cend();it++) cout << *it << " ";
	cout << endl;
}
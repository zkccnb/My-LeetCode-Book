#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	//用map旨在借助数字出现次数解决问题
	vector<int> intersection_map(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> num;
		vector<int> ret;
		for (auto it = nums1.begin(); it != nums1.end(); it++)
		{
			if (!num[*it]) num[*it]++;
		}
		for (auto it = nums2.begin(); it != nums2.end(); it++)
		{
			if (num[*it] < 2 && num[*it]>0) num[*it]++;
		}
		for (auto it = num.begin(); it != num.end(); it++)
		{
			if (it->second > 1) ret.push_back(it->first);
		}
		return ret;
	}
	//用set其实就够了，在空间上会节省一点，利用了非muti容器会把重复的元素自动剔除掉
	//但写的时候要注意利用迭代器区间进行初始化容器
	vector<int> intersection_set(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> num(nums1.begin(), nums1.end());
		unordered_set<int> ret;
		for (auto it = nums2.begin(); it != nums2.end(); it++)
		{
			if (num.find(*it) != num.end()) ret.insert(*it);
		}

		return vector<int>(ret.begin(), ret.end());
	}
};
int main()
{
	vector<int> a = { 4,9,5,6,6 };
	vector<int> b = { 9,4,9,8,4,7,7 };
	vector<int> ret = Solution().intersection_map(a,b);
	for (auto it = ret.cbegin(); it != ret.cend(); it++) cout << *it << " ";
}
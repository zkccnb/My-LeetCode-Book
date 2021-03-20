#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> map;//非常细节的问题！：size_t不要进行绝对值abs运算，会报错
		for (auto i = 0; i < nums.size(); i++)
		{
			auto p_find = map.find(nums[i]);
			if (p_find == map.end()) map[nums[i]] = i;
			else
			{
				if (abs(p_find->second - i) <= k) return true;
				else map[nums[i]] = i;
			}
		}
		return false;
	}
};

int main()
{
	vector<int> a = { 1,0,1,1 };
	int k = 1;
	Solution so;
	bool is_nearby = so.containsNearbyDuplicate(a, k);
	//for (auto it = vec.cbegin(); it != vec.cend(); it++) cout << *it << " ";
	cout << is_nearby << endl;
}
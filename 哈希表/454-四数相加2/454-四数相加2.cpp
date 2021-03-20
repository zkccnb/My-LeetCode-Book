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
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> half_map;
		size_t times = 0;
		for (const auto r_A : A)
		{
			for (const int r_B : B)
			{
				half_map[r_A + r_B]++;//记录前两个数组各元素的和分别出现了多少次
			}
		}
		for (const int r_C : C)
		{
			for (const int r_D : D)
			{
				//对后两个数组中的所有两两之和，寻找他是不是hash中某个元素的相反数
				const auto it = half_map.find(-1 * (r_C + r_D));
				//如果是，计数应该加上前两个数组和出现后两个数组和相反数的次数
				if (it != half_map.end()) times += (it->second);
			}
		}
		return times;
	}
};
int main()
{
	vector<int> a = { -1,1 };
	vector<int> b = { 1 };
	vector<int> c = { 0 };
	vector<int> d = { -2,2,1 };
	int times = Solution().fourSumCount(a, b, c, d);
	//for (auto it = ret.cbegin(); it != ret.cend(); it++) cout << *it << " ";
	cout << times << endl;
}
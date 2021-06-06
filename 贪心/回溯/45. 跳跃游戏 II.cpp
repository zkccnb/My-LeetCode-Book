#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//很难的一道题！
class Solution {
public:
	int jump(vector<int>& nums) {
		int cur_cover = 0, next_cover = 0;
		int step = 0;
		int nums_s = nums.size();
		for (int i = 0; i < nums_s - 1; i++) {
			next_cover = max(nums[i] + i, next_cover);//看看这一步覆盖的最远距离是多少，一旦这一步走到了覆盖距离的边缘，准备更新cur_cover
			if (i == cur_cover)//已经走到了当前覆盖最远距离的下标，说明需要接着往下走一步，并更新cur_cover
			{
				cur_cover = next_cover;
				step++;
			}
		}
		return step;
	}
};
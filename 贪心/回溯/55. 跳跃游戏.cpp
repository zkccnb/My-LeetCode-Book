#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//使用最远覆盖范围判断是否能到达最后一个元素位置
//“最远覆盖范围”内可随意跳跃到任何点是一个很重要的隐含条件！
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int nums_s = nums.size();
		int cover_area = 0;//最远的覆盖范围
		//在最远覆盖范围内，可以到达任意位置，我们检查当前最远覆盖范围的可跳跃距离，看看可不可以更新最远覆盖范围
		for (int i = 0; i <= cover_area; i++) {
			cover_area = max(cover_area, i + nums[i]);
			if (cover_area >= nums_s - 1) return true;
		}
		return false;
	}
};
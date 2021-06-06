#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//这个题就是。。根本不可能想到的。。背题吧，但是我感觉面试也不会考这种题吧。。
class Solution {
public:
	int candy(vector<int>& ratings) {
		int ratings_s = ratings.size();
		int ret = 0;
		vector<int> candy(ratings_s, 1);
		candy[0] = 1;
		//从左往右遍历，右边孩子的评分比左边高，则右边孩子比左边的多一个，否则右边孩子分1个
		for (int i = 1; i < ratings_s; i++) {
			if (ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
		}
		//从右往左遍历，右边孩子的评分比左边高，则左边孩子分配max(candy[i+1]+1,candy[i])个。。
		//这。。太变态了，背题吧。。。
		for (int i = ratings_s - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) candy[i] = max(candy[i + 1] + 1, candy[i]);
		}
		for (auto r_candy : candy) {
			ret += r_candy;
		}
		return ret;
	}
};
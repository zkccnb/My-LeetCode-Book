#include<iostream>
#include<vector>
#include<algorithm>
//这并不是贪心的做法啊孩子，贪心是可以降低复杂度的。。
//而且你这个写法有个测例是错的。。
using namespace std;
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int maxL = 1;
		bool times = false;
		for (int i = 0; i < nums.size() - 1; i++) {
			times = (nums[i + 1] > nums[i]);
			int cur_i = i;
			int cur_max = 1;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] == nums[cur_i]) continue;
				if ((nums[j] > nums[cur_i]) == times)
				{
					cur_max++;
					cur_i++;
					times = !times;
				}
			}
			maxL = max(maxL, cur_max);
		}
		return maxL;
	}
};
//这是一种十分巧妙的方法，类似PID算法计算微分项输出，可以将时间复杂度降低到O(n)
//放心吧，不告诉你这么做根本想不到，这其实是一种贪心，局部最优解就是curDiff与preDiff异号
//class Solution {
//public:
//	int wiggleMaxLength(vector<int>& nums) {
//		int curDiff = 0, preDiff = 0;
//		int maxL = 1;
//		for (int i = 1; i < nums.size(); i++) {
//			curDiff = nums[i] - nums[i - 1];//计算当前差值
//			//如果当前差值和上一次差值符号相反则说明子序列的长度应该加1
//			//注意，如果preDiff=0，说明上一次有两个一样的数字，只要这一次两个数字不一样，子序列长度就加1
//			if (curDiff < 0 && preDiff >= 0 || curDiff>0 && preDiff <= 0)
//			{
//				maxL++;
//				preDiff = curDiff;//更新上一次差值
//			}
//		}
//		return maxL;
//	}
//};
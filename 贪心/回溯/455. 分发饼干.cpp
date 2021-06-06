#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//这是贪心的入门题。。但如果一开始思路错了会给自己挖坑。。。
//最简单的做法是排序后，从后向前遍历孩子数组，如果当前的孩子可以满足，饼干的索引才向前移动一个，否则饼干数组不移动，考察下一个胃口更小的孩子能不能用此饼干满足。。
//如果你从前向后遍历孩子数组，也不是做不出来，可是你会发现每一次移动孩子索引，都要移动饼干索引，而且如果当前的孩子不能满足，还得向后继续移动饼干索引。。。。很容易碰到边界出错。。。
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int satisfy = 0;
		int si = s.size() - 1;
		for (int gi = g.size() - 1; gi >= 0; gi--) {
			if (si >= 0 && s[si] >= g[gi])
			{
				satisfy++;
				si--;//只有当前孩子满足才向前移动一次饼干索引；如果当前孩子不满足，继续看前一个孩子（胃口更小的一个孩子）是否可以用这个饼干来满足
			}
		}
		return satisfy;
	}
};
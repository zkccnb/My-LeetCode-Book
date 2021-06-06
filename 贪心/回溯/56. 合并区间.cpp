#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//这属于一类题：重合区间问题
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//重合区间问题基本都要先对数组排序，就按照区间左端点大小排序即可
		sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {return i1[0] < i2[0]; });
		list<vector<int>> intervals_l(intervals.begin(), intervals.end());
		int i = 0;
		//一定要小心链表的迭代器！只能++/--/==/!=；不能+1/-1/>/<
		for (auto it = intervals_l.begin(); it != intervals_l.end(); i++) {
			//两个相邻的区间有重合部分
			if (i < intervals.size() - 1 && intervals[i][1] >= intervals[i + 1][0])
			{
				//先保存迭代器，否则一会儿删除了就会导致崩溃
				auto e_it = it;
				it++;
				//这里的处理要谨慎
				intervals[i + 1][0] = min(intervals[i][0], intervals[i + 1][0]);
				intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
				*it = intervals[i + 1];//改变右边的区间（如上面的操作）
				intervals_l.erase(e_it);//删除左边的区间
			}
			else it++;//这里不要忘了把迭代器++
		}
		return vector<vector<int>>(intervals_l.begin(), intervals_l.end());//返回的时候直接利用构造函数构造一个临时数组也是一个容易忽视的技巧
	}
};
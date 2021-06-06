#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//这属于一类题：重合区间问题
//一些细节的处理技巧要注意，再看的时候仔细看看注释
class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty()) return 0;
		//这里有一个很细节的问题！频繁调用的函数传参尽可能引用传递，值传递会使速度变慢接近10倍！
		sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2) {return p1[0] < p2[0]; });
		int ret = 1;//至少有一个气球，则至少需要一只箭
		//从第二个气球开始
		for (int i = 1; i < points.size(); i++) {
			if (points[i - 1][1] < points[i][0]) ret++;//左边气球的右边界小于右边气球的左边界，说明两个气球没有重叠区域，需要加一只箭
			else//两个气球有重叠
			{
				//这里的处理非常具有技巧性。。你想不到的。。
				//箭数量不增加，且把右边气球的右边界变成他左边气球右边界
				//这样操作目的在于遍历下一个气球时就不会考虑到此气球了，相当于把这个气球去掉
				points[i][1] = min(points[i - 1][1], points[i][1]);
			}
		}
		return ret;
	}
};

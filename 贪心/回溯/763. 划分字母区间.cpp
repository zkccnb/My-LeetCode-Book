#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
//做了56.合并区间，你就会发现这道题如果用哈希表转换一下直接就变成一道合并区间的题了。。
//只不过这么做效率很低。。。
class Solution {
public:
	vector<int> partitionLabels(string S) {
		unordered_map<char, vector<int>> mp;
		//用哈希表记录每个字母第一次出现的位置，最后一次出现的位置，两个位置存在vec里
		for (int i = 0; i < S.size(); i++) {
			if (mp[S[i]].empty()) mp[S[i]].push_back(i);
			else if (mp[S[i]].size() == 1) mp[S[i]].push_back(i);
			else mp[S[i]][1] = i;
		}
		vector<vector<int>> vec;//获取merge的输入参数
		int i = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			vector<int> inter = it->second;
			if (inter.size() == 1) inter.push_back(inter[0]);
			vec.push_back(inter);
			i++;
		}
		vector<vector<int>> merged_vector = merge(vec);//调用merge
		vector<int> ret;
		//获取结果就行了
		for (int i = 0; i < merged_vector.size(); i++) {
			ret.push_back(merged_vector[i][1] - merged_vector[i][0]+1);
		}
		return ret;
	}
	//56.合并区间，合并所有带有重复的区间，返回的区间是没有重复部分的
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
//int main() {
//	string s = "ababcbacadefegdehijhklij";
//	vector<int> ret = Solution().partitionLabels(s);
//	for (int i = 0; i < ret.size(); i++) {
//		cout << ret[i] << " ";
//	}
//	cout << endl;
//}
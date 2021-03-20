#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
class Solution {
public:
	//用内置的sort实现排序
	vector<int> topKFrequent_sort(vector<int>& nums, int k) {
		unordered_map<int, int> freqMap;
		vector<int> ret;
		for (const auto num : nums)
		{
			freqMap[num]++;
		}
		//冷知识：没法给无序容器排序，只能把内容复制到vec里
		vector<pair<int, int>> mapPair(freqMap.begin(), freqMap.end());
		sort(mapPair.begin(), mapPair.end(), [](pair<int, int> p1, pair<int, int>p2){ return p1.second > p2.second; });
		//一定要熟练掌握lambada表达式的使用，写题的时候总不好弄一个仿函数或者函数，函数指针什么的吧。。。
		//但这个地方用sort效率是不高的，因为实际上没有必要对所有的元素完全排序，只要找到前k个就行，这种不完全排序用堆是最好的了
		auto p_mapPair = mapPair.begin();
		for (auto i = 0; i < k; i++)
		{
			ret.push_back(p_mapPair->first);
			p_mapPair++;
		}
		return ret;
	}
	//用更高效一点的小根堆实现排序
	vector<int> topKFrequent_minheap(vector<int>& nums, int k) {
		unordered_map<int, int> freqMap;
		vector<int> ret;
		for (const auto num : nums)
		{
			freqMap[num]++;
		}
		//这个东西不接受lambada表达式。。。只能自己写仿函数了
		priority_queue<pair<int, int>,vector<pair<int, int>> ,minHeapCom> pri_q;
		for (const auto thePair : freqMap)
		{
			pri_q.push(thePair);
			if (pri_q.size() > k) pri_q.pop();
		}
		while (pri_q.size())
		{
			ret.push_back(pri_q.top().first);
			pri_q.pop();
		}
		return ret;
	}
	class minHeapCom {
	public:
		bool operator()(pair<int, int> p1, pair<int, int>p2)
		{
			return p1.second > p2.second;//堆的仿函数写法好像是和其他的是反过来的
		}
	};
};
int main()
{
	vector<int> nums = { 1,1,1,2,3,4,4,5,5,5,5 };
	vector<int> ret = Solution().topKFrequent_minheap(nums,2);
	for (auto it = ret.cbegin(); it != ret.cend(); it++)
	{
		cout << *it<<' ';
	}
	cout << endl;
}
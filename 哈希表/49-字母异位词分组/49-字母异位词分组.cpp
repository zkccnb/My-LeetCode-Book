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
	typedef vector<vector<string>> ret_t;
	//第一次想到的方法，对所有str两两比较，判断是不是异位词，但这样太慢了
	//时间复杂度：n:str长度，m:strs中str的个数：：O((n+n)m^2)（最坏情况）
	vector<vector<string>> groupAnagrams_findAnag(vector<string>& strs) {
		ret_t ret;
		auto cte = ret.end();
		bool isFind = false;
		for (const auto str:strs)
		{
			for (auto p_vec=ret.begin(); p_vec != cte; p_vec++)
			{
				if (isAnag(str, *(p_vec->begin()) )) { isFind = true; p_vec->push_back(str); break; }
				else isFind = false;
			}
			if (!isFind)
			{
				ret.push_back({str});
				cte = ret.end();
			}
		}
		return ret;
	}
	bool isAnag(const string& s, const string& t)
	{
		if (s.size() != t.size()) return false;
		int* arr = new int[26]();
		for (auto i = 0; i != s.size(); i++)
		{
			arr[s[i] - 'a']++;
			arr[t[i] - 'a']--;
		}
		for (auto i = 0; i != 26; i++)
		{
			if (arr[i]) return false;
		}
		delete[] arr;
		return true;
	}
	//优化的方法，其实不用非得两两比较异位词，直接比较strs各元素中各字母是否一样就行了
	//时间复杂度：n:str长度，m:strs中str的个数：：O(mnlogn)（最坏情况）
	//当数据很多时，m>>n，这个时候你那种方法就很拙劣了，m对时间的影响要远大于n！
	vector<vector<string>> groupAnagrams_nofindAnag(vector<string>& strs) {
		ret_t ret;
		unordered_map<string, vector<string>> map;
		//优化时间时，哈希表键值对的选择非常重要，这里的选择就显得十分巧妙
		//key：当前遍历到的字符串：：把当前字符串排好序后存入存入哈希表
		//value：一个异位词元组：：因为排好序的异位词是相等的，所以直接将当前词添加进对应的异位词元组
		for (const auto str : strs)
		{
			auto sorted = str;
			sort(sorted.begin(), sorted.end());
			map[sorted].push_back(str);
		}
		for (const auto e_map : map) ret.push_back(e_map.second);
		return ret;
	}
};
int main()
{
	
	vector<string> a = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> ret = Solution().groupAnagrams_nofindAnag(a);
	for (auto it = ret.cbegin(); it != ret.cend(); it++)
	{
		for (auto it1 = it->cbegin(); it1 != it->cend(); it1++)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}
}
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
	//这道题要求的是：两个字符串出现的字母一样，且出现某字母的次数一样
	//想到这两个维度其实容易想到使用hash（unordered_map）
	//key：字母 char
	//value：出现次数 int
	//对顺序没有要求，键不需要重复，且有两个考虑维度
public:
	//排序法，时间复杂度O(nlogn+n)=O(nlogn),空间复杂度O(1)
	bool isAnagram_sort(string s, string t) {
		if (s.size() != t.size()) return false;
		sort(s.begin(),s.end());
		sort(t.begin(), t.end());
		for (auto i = 0; i != t.size(); i++)
		{
			if (s[i] != t[i]) return false;
		}
		return true;
	}
	//哈希法，时间复杂度O(n),空间复杂度O(n)
	bool isAnagram_hash(string s, string t) {
		if (s.size() != t.size()) return false;
		unordered_map<char, int> hashString;//key:字母；value:出现次数
		for (auto i = 0; i != s.size(); i++)
		{
			hashString[s[i]]++;
			hashString[t[i]]--;
		}
		for (auto it = hashString.begin(); it != hashString.end(); it++)
		{
			if (it->second) return false;//value不是0说明肯定不是异位词
		}
		return true;
	}
	//哈希数组法，时间复杂度O(n),空间复杂度O(1)
	bool isAnagram_hasharr(string s, string t) {
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
};

int main()
{
	vector<int> a = { 1,2,3,4 };
	string s = "zkcc";
	string t = "zkck";
	Solution so;
	bool is_an = so.isAnagram_sort(s,t);
	//for (auto it = vec.cbegin(); it != vec.cend(); it++) cout << *it << " ";
	cout <<is_an<< endl;
}
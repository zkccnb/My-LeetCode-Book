#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
	//你之前的想法不是不行，但是太慢了，答案的方法可以说刀刀致命，省略了很多多余的操作
	int lengthOfLongestSubstring(string s) {
		if (!s.size()) return 0;
		unordered_set<char> judgeDup_set;
		int slow = 0;
		int n = s.size();//size()返回类型为size_t，size_t型的数据不能和负数比较！
		//会把负数补码强制转换成无符号数，结果和你的预期肯定不一样！
		int fast = -1;
		int length = 0;
		for (slow = 0; slow < n; slow++)
		{
			if (slow != 0) judgeDup_set.erase(s[slow - 1]);
			while (fast+1 < n && !judgeDup_set.count(s[fast + 1]))
			{
				judgeDup_set.insert(s[fast + 1]);
				fast++;
			}
			length = max(length, fast - slow + 1);
		}
		return length;
	}
	
		//int lengthOfLongestSubstring(string s) {
		//	unordered_map<char, bool> judgeDup_map;
		//	size_t slow, fast = 0;
		//	size_t length, max_length = 1;
		//	for (slow = 0; slow < s.size(); slow++)
		//	{
		//		fast = slow + 1;
		//		judgeDup_map[s[slow]] = true;
		//		if (fast == s.size()) return max_length;//字符串只有一个字符
		//		while (judgeDup_map[s[fast]] != true)
		//		{
		//			judgeDup_map[s[fast]] = true;
		//			length++;
		//			if (fast < s.size() - 1) fast++;
		//			else break;
		//		}
		//		if (length > max_length) max_length = length;
		//		length = 1;
		//		if (fast == s.size() - 1) return max_length;//快指针到头了
		//		judgeDup_map.clear();
		//	}
		//	return 0;//空字符串
		//}
};

int main() {
	string h = "pwwkewa";
	//string n = "sipp";
	/*string h = "aabaabaafcd";
	string n = "aabaaf";*/
	/*string h = "hello";
	string n = "ll";*/
	/*string h = "ccd";
	string n = "cd";*/
	int ret = Solution().lengthOfLongestSubstring(h);
	cout << ret << endl;
}
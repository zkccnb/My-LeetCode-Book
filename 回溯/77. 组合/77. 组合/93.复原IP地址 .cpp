#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
//只要搞懂了递归分割字符串问题，这个题其实不难，只不过判断条件（剪枝）稍多了点
//细心理清楚判断条件这个题可以一次写出来
using namespace std;
class Solution {
public:
	vector<string> ret;
	string ret_line;
	string m_s;
	size_t count_8;//8位ip数大于4个则返回
	vector<string> restoreIpAddresses(string s) {
		if (s.size() > 12) return ret;//输入串的长度大于12直接退出（防止那种10000个字符的测例使程序崩溃）
		m_s = s;
		count_8 = 0;
		backtracking(0);
		return ret;
	}
	void backtracking(int cur) {
		if (cur >= m_s.size())//只有cur>size才说明找到了一组备选结果
		{
			ret_line.pop_back();//把得到候选结果中最后一个点去掉
			//找到备选结果后才能对ip的8位地址个数判断！（只要不是4个8位地址直接pass）
			if (count_8 != 4) return;
			ret.push_back(ret_line);//这才算找到了正确的结果
			return;
		}
		for (int i = cur; i < m_s.size(); i++) {
			//感觉我写的剪枝有些多余，好像有几个是没必要的。。
			if (i - cur >= 3) return;//十进制地址长度≥3直接pass（2555）
			if (m_s[cur] - '0' > 2 && i - cur >= 2) return;//如果cur位的数字是大于2的，那么地址长度≥2就得pass了（344）
			if (m_s[cur] == '0' && i - cur >= 1) return;//如果cur位的数字是0，那么地址长度≥1就得pass了（01）
			if (stoi(m_s.substr(cur, i - cur + 1)) > 255) return;//(cur-i)子串，即当前选中的子串＞255也得pass
			string ip_string = m_s.substr(cur, i - cur + 1);
			//int ip = stoi(ip_string);
			ret_line+=ip_string;
			ret_line.push_back('.');
			count_8++;
			backtracking(i + 1);
			count_8--;
			if(*(ret_line.end()-1)=='.') ret_line.pop_back();//如果最后一位是'.'，则把点去掉
			ret_line=ret_line.substr(0,ret_line.size()-ip_string.size());//字符串的撤销操作也要注意
		}
	}
};
int main()
{
	string s = "2112";
	//string s = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	clock_t start_time = clock(); //获取此程序段开始执行时间
	vector<string> ret = Solution().restoreIpAddresses(s);
	clock_t end_time = clock();
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j];
		}
		cout << endl;
	}
	cout << "算法执行时间：" << static_cast<double> (end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;

}
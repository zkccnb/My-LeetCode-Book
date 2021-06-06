#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//放心吧，贪心的最优解法你根本想不到的哈哈哈哈
//先把数字转换成字符串，然后从右到左遍历，如果左边的数比右边的数大，则把左边的数-1，右边的数置为9；这就是局部最优解
//你说，这种变态的想法谁能想到？？？想不到的孩子。。。
class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		string str_n = to_string(N);
		char flag = str_n.size();//记录从左至右哪一位开始第一次需要调整
		for (int i = str_n.size() - 1; i > 0; i--) {
			if (str_n[i - 1] > str_n[i]) {
				str_n[i - 1]--;
				flag = i;
			}
		}
		for (int i = flag; i < str_n.size(); i++) {
			str_n[i] = '9';
		}
		return stoi(str_n);
	}
};
//int main() {
//	cout << Solution().monotoneIncreasingDigits(332) << endl;
//}
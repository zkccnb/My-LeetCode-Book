#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
using namespace std;
//这个题怎么说呢。。如果想执行效果很好，就是硬拽逻辑，没啥思想
//硬拽逻辑还是很复杂的，面试根本不可能写出来。。。。建议二轮的时候看看有没有什么简单想的方法
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		int size = s.size();
		string ret;
		int data_j,j;
		for (auto i = 0; i < numRows; i++)//行
		{
			data_j = i ;
			j = 0;
			while (data_j < size)//列
			{
				if (!j)//第一列
					ret.push_back(s[i]);
				else if (j % 2)//奇数列
				{
					if ((2 * numRows - 2)== 2 * i) { j++; continue; }//如果此位置为顶点，则跳过
					if (data_j + (2 * numRows - 2) - 2*i >= size) break;
					else ret.push_back(s[data_j + (2 * numRows - 2) - 2*i]);
					data_j += (2 * numRows - 2) - 2*i;
				}
				else//偶数列
				{
					if (i == 0) { j++; continue; }//如果此位置为顶点，则跳过
					if (data_j + 2 * i >= size) break;
					else ret.push_back(s[data_j + 2 * i]);
					data_j += 2 * i;
				}
				j++;
			}
		}
		return ret;
	}
};

int main() {
	string h = "PAYPALISHIRING";//3 4
	//string h = "A";//1
	//string h = "ABCD";//3
	string ret = Solution().convert(h, 4);
	cout << ret << endl;
}

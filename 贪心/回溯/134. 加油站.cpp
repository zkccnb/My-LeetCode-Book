#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
//一道很经典的贪心问题！暴力解法很好想，但贪心解法确实不好想。。仔细读读注释吧
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		//curSum：当前剩余的油量
		//totoalSum：从头到尾剩余的油量
		int curSum = 0, totoalSum = 0;
		int rest = 0;
		int begin = 0;
		for (int i = 0; i < gas.size(); i++) {
			rest = gas[i] - cost[i];
			curSum += rest;
			totoalSum += rest;
			//如果curSum<0,说明从头到此位置都不能作为起点
			//此时应把curSum置0，从下一位置重新计算
			if (curSum < 0)
			{
				curSum = 0;
				begin = i + 1;//同时，begin置为下一位置（如果下一位置的curSum>0，那么就是他了！）
				//不用担心之后的位置会有更耗油的，有的话还会进入这个判断，重新置begin的位置！
			}
		}
		if (totoalSum < 0) return -1;//如果totoalSum小于0，那么不论如何都不可能走完一圈
		return begin;//totoalSum不为0时，把找到的begin返回
	}
};
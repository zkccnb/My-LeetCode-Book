#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//主体逻辑你或许能想到，但在-fee的操作太秀了。。真的真的想不到。。。
//就是要选好一个买入时机和卖出时机，买入时机好确定，碰到更低的价格就设置买入价格；
//卖出的时机非常不好确定！
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int inprice = prices[0];//买入价
		int ret = 0;
		for (int i = 0; i < prices.size(); i++) {
			//如果有更低的价格则买入
			if (prices[i] < inprice) inprice = prices[i];
			//如果此时股价大于等于买入股价，但算上手续费又亏了，则不做操作
			if (prices[i] >= inprice && prices[i] <= inprice + fee) continue;
			//如果按当日价格卖出考虑手续费也不亏，则考虑要不要卖出（不一定非得卖出！）
			if (prices[i] > inprice + fee)
			{
				ret += prices[i] - inprice - fee;
				//这里一定要减去手续费，为什么呢？
				//因为这里算出的inprice下一步马上要和下一个交易日的price比较
				//如果下一交易日的价格prices[i+1]大于prices[i]-fee，则说明i交易日应持有股票继续等待高价，现在卖出去的话肯定不能赚到最多；
				//如果prices[i+1]小于prices[i]-fee，就说明下一交易日的价格更低，i交易日卖出，i+1再买进会赚的更多！
				//讲道理这个可能真的想不到。。。
				inprice = prices[i] - fee;
			}
		}
		return ret;
	}
};
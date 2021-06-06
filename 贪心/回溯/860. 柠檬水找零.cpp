#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//这道题整体来看属于一个“模拟”
//但给20块的找零过程实际是一个贪心，需要优先找一个10块钱，因为5块钱可能会有更多的用处，而10块钱只能用于找零20块钱
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int five = 0, ten = 0;//20美元不能用来找零，没用，所以不记了
		for (auto bill : bills) {
			if (bill == 5)//给5块，不用找零，5++
			{
				five++;
				continue;
			}
			else if (bill == 10)//给10块
			{
				if (five--)//如果有5块钱零钱，则找的开；5--，10++
				{
					ten++;
					continue;
				}
				else return false;//如果没有5块零钱，返回
			}
			else//给20块
			{
				if (ten > 0)//如果有10块钱零钱，则优先找10块钱的，这是一个贪心！10--
				{
					ten--;
					if (five--) continue;//如果有5块钱零钱，则找的开；5--
					else return false;//如果没有5块零钱，返回
				}
				else//如果没有10块钱零钱，则只能找3个5块了
				{
					if (five > 3)
					{
						five -= 3;
						continue;//如果3个有5块钱零钱，则找的开；5-=3
					}
					else return false;//如果没有，返回
				}
			}
		}
		return true;
	}
};
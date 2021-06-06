#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
//һ���ܾ����̰�����⣡�����ⷨ�ܺ��룬��̰�Ľⷨȷʵ�����롣����ϸ����ע�Ͱ�
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		//curSum����ǰʣ�������
		//totoalSum����ͷ��βʣ�������
		int curSum = 0, totoalSum = 0;
		int rest = 0;
		int begin = 0;
		for (int i = 0; i < gas.size(); i++) {
			rest = gas[i] - cost[i];
			curSum += rest;
			totoalSum += rest;
			//���curSum<0,˵����ͷ����λ�ö�������Ϊ���
			//��ʱӦ��curSum��0������һλ�����¼���
			if (curSum < 0)
			{
				curSum = 0;
				begin = i + 1;//ͬʱ��begin��Ϊ��һλ�ã������һλ�õ�curSum>0����ô�������ˣ���
				//���õ���֮���λ�û��и����͵ģ��еĻ������������жϣ�������begin��λ�ã�
			}
		}
		if (totoalSum < 0) return -1;//���totoalSumС��0����ô������ζ�����������һȦ
		return begin;//totoalSum��Ϊ0ʱ�����ҵ���begin����
	}
};
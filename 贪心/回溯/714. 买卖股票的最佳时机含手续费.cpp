#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//�����߼���������뵽������-fee�Ĳ���̫���ˡ����������벻��������
//����Ҫѡ��һ������ʱ��������ʱ��������ʱ����ȷ�����������͵ļ۸����������۸�
//������ʱ���ǳ�����ȷ����
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int inprice = prices[0];//�����
		int ret = 0;
		for (int i = 0; i < prices.size(); i++) {
			//����и��͵ļ۸�������
			if (prices[i] < inprice) inprice = prices[i];
			//�����ʱ�ɼ۴��ڵ�������ɼۣ��������������ֿ��ˣ���������
			if (prices[i] >= inprice && prices[i] <= inprice + fee) continue;
			//��������ռ۸���������������Ҳ����������Ҫ��Ҫ��������һ���ǵ���������
			if (prices[i] > inprice + fee)
			{
				ret += prices[i] - inprice - fee;
				//����һ��Ҫ��ȥ�����ѣ�Ϊʲô�أ�
				//��Ϊ���������inprice��һ������Ҫ����һ�������յ�price�Ƚ�
				//�����һ�����յļ۸�prices[i+1]����prices[i]-fee����˵��i������Ӧ���й�Ʊ�����ȴ��߼ۣ���������ȥ�Ļ��϶�����׬����ࣻ
				//���prices[i+1]С��prices[i]-fee����˵����һ�����յļ۸���ͣ�i������������i+1�������׬�ĸ��࣡
				//�����������������벻��������
				inprice = prices[i] - fee;
			}
		}
		return ret;
	}
};
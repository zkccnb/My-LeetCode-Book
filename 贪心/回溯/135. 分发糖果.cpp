#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//�������ǡ��������������뵽�ġ�������ɣ������Ҹо�����Ҳ���ῼ������ɡ���
class Solution {
public:
	int candy(vector<int>& ratings) {
		int ratings_s = ratings.size();
		int ret = 0;
		vector<int> candy(ratings_s, 1);
		candy[0] = 1;
		//�������ұ������ұߺ��ӵ����ֱ���߸ߣ����ұߺ��ӱ���ߵĶ�һ���������ұߺ��ӷ�1��
		for (int i = 1; i < ratings_s; i++) {
			if (ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
		}
		//��������������ұߺ��ӵ����ֱ���߸ߣ�����ߺ��ӷ���max(candy[i+1]+1,candy[i])������
		//�⡣��̫��̬�ˣ�����ɡ�����
		for (int i = ratings_s - 2; i >= 0; i--) {
			if (ratings[i] > ratings[i + 1]) candy[i] = max(candy[i + 1] + 1, candy[i]);
		}
		for (auto r_candy : candy) {
			ret += r_candy;
		}
		return ret;
	}
};
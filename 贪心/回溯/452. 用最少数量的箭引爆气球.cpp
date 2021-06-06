#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//������һ���⣺�غ���������
//һЩϸ�ڵĴ�����Ҫע�⣬�ٿ���ʱ����ϸ����ע��
class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty()) return 0;
		//������һ����ϸ�ڵ����⣡Ƶ�����õĺ������ξ��������ô��ݣ�ֵ���ݻ�ʹ�ٶȱ����ӽ�10����
		sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2) {return p1[0] < p2[0]; });
		int ret = 1;//������һ��������������Ҫһֻ��
		//�ӵڶ�������ʼ
		for (int i = 1; i < points.size(); i++) {
			if (points[i - 1][1] < points[i][0]) ret++;//���������ұ߽�С���ұ��������߽磬˵����������û���ص�������Ҫ��һֻ��
			else//�����������ص�
			{
				//����Ĵ���ǳ����м����ԡ������벻���ġ���
				//�����������ӣ��Ұ��ұ�������ұ߽�������������ұ߽�
				//��������Ŀ�����ڱ�����һ������ʱ�Ͳ��ῼ�ǵ��������ˣ��൱�ڰ��������ȥ��
				points[i][1] = min(points[i - 1][1], points[i][1]);
			}
		}
		return ret;
	}
};

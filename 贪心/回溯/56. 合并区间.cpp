#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//������һ���⣺�غ���������
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//�غ��������������Ҫ�ȶ��������򣬾Ͱ���������˵��С���򼴿�
		sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {return i1[0] < i2[0]; });
		list<vector<int>> intervals_l(intervals.begin(), intervals.end());
		int i = 0;
		//һ��ҪС������ĵ�������ֻ��++/--/==/!=������+1/-1/>/<
		for (auto it = intervals_l.begin(); it != intervals_l.end(); i++) {
			//�������ڵ��������غϲ���
			if (i < intervals.size() - 1 && intervals[i][1] >= intervals[i + 1][0])
			{
				//�ȱ��������������һ���ɾ���˾ͻᵼ�±���
				auto e_it = it;
				it++;
				//����Ĵ���Ҫ����
				intervals[i + 1][0] = min(intervals[i][0], intervals[i + 1][0]);
				intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
				*it = intervals[i + 1];//�ı��ұߵ����䣨������Ĳ�����
				intervals_l.erase(e_it);//ɾ����ߵ�����
			}
			else it++;//���ﲻҪ���˰ѵ�����++
		}
		return vector<vector<int>>(intervals_l.begin(), intervals_l.end());//���ص�ʱ��ֱ�����ù��캯������һ����ʱ����Ҳ��һ�����׺��ӵļ���
	}
};
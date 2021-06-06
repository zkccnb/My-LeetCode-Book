#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//˼·��135.�ַ��ǹ��е����Ȱ�һ��ά�Ƚ���̰�ģ��Ȱ���ߴӴ�С�������򣩣�
//�ٰ���һ��ά��̰�ģ����ΰ��ź����Ԫ�ز��뵽����Ĵ�ǰ�������ĵ�k��λ�� (k=people[i][1])
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		//�Ȱ���ߴӴ�С���������ͬ��kֵС������ǰ��
		sort(people.begin(), people.end(), [](vector<int> p1, vector<int> p2) {if (p1[0] == p2[0]) return p1[1] < p2[1]; else return p1[0] > p2[0]; });
		//return people;
		list<vector<int>> people_list;//Ϊ�˱��ڲ��룬����������ɺ���Ĳ���
		//���ΰ�Ԫ�ز��뵽��Ԫ��kֵ��Ӧ�������е�λ��
		for (auto r_people : people) {
			int insert_pos = r_people[1];
			auto it = people_list.begin();
			while (insert_pos--) it++;
			people_list.insert(it, r_people);
		}
		//list˫��������Ȼ��end()����������list�ṩ�ĵ�������һ��˫�����������֧��������ʲ�������֧�ֱȽϣ�ֻ�����������ˣ���
		//int i=0;
		// for(auto r_peolist:people_list){
		//     people[i++]=r_peolist;
		// }
		// return people;
		return vector<vector<int>>(people_list.begin(), people_list.end());
	}
};
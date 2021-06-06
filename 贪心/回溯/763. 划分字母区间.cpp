#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;
//����56.�ϲ����䣬��ͻᷢ�����������ù�ϣ��ת��һ��ֱ�Ӿͱ��һ���ϲ���������ˡ���
//ֻ������ô��Ч�ʺܵ͡�����
class Solution {
public:
	vector<int> partitionLabels(string S) {
		unordered_map<char, vector<int>> mp;
		//�ù�ϣ���¼ÿ����ĸ��һ�γ��ֵ�λ�ã����һ�γ��ֵ�λ�ã�����λ�ô���vec��
		for (int i = 0; i < S.size(); i++) {
			if (mp[S[i]].empty()) mp[S[i]].push_back(i);
			else if (mp[S[i]].size() == 1) mp[S[i]].push_back(i);
			else mp[S[i]][1] = i;
		}
		vector<vector<int>> vec;//��ȡmerge���������
		int i = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			vector<int> inter = it->second;
			if (inter.size() == 1) inter.push_back(inter[0]);
			vec.push_back(inter);
			i++;
		}
		vector<vector<int>> merged_vector = merge(vec);//����merge
		vector<int> ret;
		//��ȡ���������
		for (int i = 0; i < merged_vector.size(); i++) {
			ret.push_back(merged_vector[i][1] - merged_vector[i][0]+1);
		}
		return ret;
	}
	//56.�ϲ����䣬�ϲ����д����ظ������䣬���ص�������û���ظ����ֵ�
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
//int main() {
//	string s = "ababcbacadefegdehijhklij";
//	vector<int> ret = Solution().partitionLabels(s);
//	for (int i = 0; i < ret.size(); i++) {
//		cout << ret[i] << " ";
//	}
//	cout << endl;
//}
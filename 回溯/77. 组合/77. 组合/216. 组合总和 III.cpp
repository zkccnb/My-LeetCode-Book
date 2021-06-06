#include<iostream>
#include<vector>
using namespace std;
//д���ݺ�����ʱ��������ѭ���������һ���жϾ͹���
//��ʱ������ܵ�ѭ�����棬��˵�����жϵ���һ����֧�ˣ���ѭ����дifelse̫���״���
//�տ�ʼ���������������Ҹо�������������Ҫ�໭���ݹ���·ͼ������˼·
class Solution {
public:
	vector<vector<int>> ret;
	vector<int> ret_line;
	int cur_sum;
	vector<vector<int>> combinationSum3(int k, int n) {
		cur_sum = 0;
		backtracking(k, n, 1);
		return ret;
	}
	void backtracking(int k, int n, int cur) {
		if (cur_sum > n) return;//�������ǰ���֦
		if (ret_line.size() == k)
		{
			if (cur_sum == n) ret.push_back(ret_line);
			return;
		}
		//�ټ�һ��
		for (int i = cur; i < (10 < n ? 10 : n); i++) {
			ret_line.push_back(i);
			cur_sum += i;
			backtracking(k, n, i + 1);
			cur_sum -= i;
			ret_line.pop_back();
		}
	}
};
//int main()
//{
//	vector<vector<int>> ret = Solution().combine(4, 2);
//	for (int i = 0; i < ret.size(); i++) {
//		for (int j = 0; j < ret[i].size(); j++) {
//			cout << ret[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
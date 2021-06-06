#include<iostream>
#include<vector>
//���ݵľ���д���������Ĵ�����Ϊ�˿��Ի��ݵ����ϲ�
//��������⿴��ʱ����������ȫ�����϶ϵ㰤���������У��������еĵݹ�·��

using namespace std;
class Solution {
private:
	vector<vector<int>> result; // ��ŷ�����������ļ���
	vector<int> path; // ������ŷ����������
	void backtracking(int n, int k, int startIndex) {
		if (path.size() == k) {
			result.push_back(path);
			return;
		}
		//���������һ����֦����ǰ����Ҫѡk-path.size()��Ԫ�ص�·�����Ѿ�ѡ��path.size()��Ԫ�أ�
		for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
			path.push_back(i); // ����ڵ� 
			backtracking(n, k, i + 1); // �ݹ�
			path.pop_back(); // ���ݣ���������Ľڵ㣬����ط��Ǿ��裡
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		result.clear(); // ���Բ�д
		path.clear();   // ���Բ�д
		backtracking(n, k, 1);
		return result;
	}
};
//����д���ǰ�line����ÿһ��ݹ�Ĳ�����������������Ҳ���볷����������!
//����/�ݹ�����һ��Ҫ�����ݹ���·����ÿһ��ݹ�ջ��ı���������������һĿ��Ȼ
//class Solution {
//private:
//	vector<vector<int>> ret; // ��ŷ�����������ļ���
//	//vector<int> ret_line; // ������ŷ����������
//	void backtracking(int n, int k, int startIndex, vector<int> ret_line) {
//		if (ret_line.size() == k) {
//			ret.push_back(ret_line);
//			return;
//		}
//		for (int i = startIndex; i <= n; i++) {
//			ret_line.push_back(i); // ����ڵ� 
//			backtracking(n, k, i + 1,ret_line); // �ݹ�
//			ret_line.pop_back(); // ���ݣ���������Ľڵ㣬����ط��Ǿ��裡
//		}
//	}
//public:
//	vector<vector<int>> combine(int n, int k) {
//		backtracking(n, k, 1, {});
//		return ret;
//	}
//};
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
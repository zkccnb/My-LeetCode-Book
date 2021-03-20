#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<vector>
using namespace std;
//һ��ʮ������ķ���
//���������з�ת->ȡת��->over
//�ɼ��������顢�����ַ�����˳��ṹ����ת�����ö�η�ת��ã������ַ����������ж����Ի�����������뵽�ģ��ܱ�����Ĳ���Ҫ������ɡ�������
//�������ַ�����ʱ���ϲ������ģ���һ������O(n2)��
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		reverse(matrix.begin(), matrix.end());//�з�ת
		for (int i = 0; i < matrix.size(); i++) {//ת��
			for (int j = 0; j < i; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};
int main() {
	vector<vector<int>> matrix = { {1, 2, 3},{5, 6, 7},{9, 10, 11} };
	Solution().rotate(matrix);
	for (auto i = 0; i < matrix.size(); i++) {
		for (auto j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
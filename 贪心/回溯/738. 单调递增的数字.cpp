#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//���İɣ�̰�ĵ����Žⷨ������벻���Ĺ�������
//�Ȱ�����ת�����ַ�����Ȼ����ҵ�������������ߵ������ұߵ����������ߵ���-1���ұߵ�����Ϊ9������Ǿֲ����Ž�
//��˵�����ֱ�̬���뷨˭���뵽�������벻���ĺ��ӡ�����
class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		string str_n = to_string(N);
		char flag = str_n.size();//��¼����������һλ��ʼ��һ����Ҫ����
		for (int i = str_n.size() - 1; i > 0; i--) {
			if (str_n[i - 1] > str_n[i]) {
				str_n[i - 1]--;
				flag = i;
			}
		}
		for (int i = flag; i < str_n.size(); i++) {
			str_n[i] = '9';
		}
		return stoi(str_n);
	}
};
//int main() {
//	cout << Solution().monotoneIncreasingDigits(332) << endl;
//}
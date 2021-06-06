#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
//ֻҪ�㶮�˵ݹ�ָ��ַ������⣬�������ʵ���ѣ�ֻ�����ж���������֦���Զ��˵�
//ϸ��������ж�������������һ��д����
using namespace std;
class Solution {
public:
	vector<string> ret;
	string ret_line;
	string m_s;
	size_t count_8;//8λip������4���򷵻�
	vector<string> restoreIpAddresses(string s) {
		if (s.size() > 12) return ret;//���봮�ĳ��ȴ���12ֱ���˳�����ֹ����10000���ַ��Ĳ���ʹ���������
		m_s = s;
		count_8 = 0;
		backtracking(0);
		return ret;
	}
	void backtracking(int cur) {
		if (cur >= m_s.size())//ֻ��cur>size��˵���ҵ���һ�鱸ѡ���
		{
			ret_line.pop_back();//�ѵõ���ѡ��������һ����ȥ��
			//�ҵ���ѡ�������ܶ�ip��8λ��ַ�����жϣ���ֻҪ����4��8λ��ֱַ��pass��
			if (count_8 != 4) return;
			ret.push_back(ret_line);//������ҵ�����ȷ�Ľ��
			return;
		}
		for (int i = cur; i < m_s.size(); i++) {
			//�о���д�ļ�֦��Щ���࣬�����м�����û��Ҫ�ġ���
			if (i - cur >= 3) return;//ʮ���Ƶ�ַ���ȡ�3ֱ��pass��2555��
			if (m_s[cur] - '0' > 2 && i - cur >= 2) return;//���curλ�������Ǵ���2�ģ���ô��ַ���ȡ�2�͵�pass�ˣ�344��
			if (m_s[cur] == '0' && i - cur >= 1) return;//���curλ��������0����ô��ַ���ȡ�1�͵�pass�ˣ�01��
			if (stoi(m_s.substr(cur, i - cur + 1)) > 255) return;//(cur-i)�Ӵ�������ǰѡ�е��Ӵ���255Ҳ��pass
			string ip_string = m_s.substr(cur, i - cur + 1);
			//int ip = stoi(ip_string);
			ret_line+=ip_string;
			ret_line.push_back('.');
			count_8++;
			backtracking(i + 1);
			count_8--;
			if(*(ret_line.end()-1)=='.') ret_line.pop_back();//������һλ��'.'����ѵ�ȥ��
			ret_line=ret_line.substr(0,ret_line.size()-ip_string.size());//�ַ����ĳ�������ҲҪע��
		}
	}
};
int main()
{
	string s = "2112";
	//string s = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
	clock_t start_time = clock(); //��ȡ�˳���ο�ʼִ��ʱ��
	vector<string> ret = Solution().restoreIpAddresses(s);
	clock_t end_time = clock();
	for (int i = 0; i < ret.size(); i++) {
		for (int j = 0; j < ret[i].size(); j++) {
			cout << ret[i][j];
		}
		cout << endl;
	}
	cout << "�㷨ִ��ʱ�䣺" << static_cast<double> (end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;

}
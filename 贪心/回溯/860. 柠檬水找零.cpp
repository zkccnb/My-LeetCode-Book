#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�����������������һ����ģ�⡱
//����20����������ʵ����һ��̰�ģ���Ҫ������һ��10��Ǯ����Ϊ5��Ǯ���ܻ��и�����ô�����10��Ǯֻ����������20��Ǯ
class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int five = 0, ten = 0;//20��Ԫ�����������㣬û�ã����Բ�����
		for (auto bill : bills) {
			if (bill == 5)//��5�飬�������㣬5++
			{
				five++;
				continue;
			}
			else if (bill == 10)//��10��
			{
				if (five--)//�����5��Ǯ��Ǯ�����ҵĿ���5--��10++
				{
					ten++;
					continue;
				}
				else return false;//���û��5����Ǯ������
			}
			else//��20��
			{
				if (ten > 0)//�����10��Ǯ��Ǯ����������10��Ǯ�ģ�����һ��̰�ģ�10--
				{
					ten--;
					if (five--) continue;//�����5��Ǯ��Ǯ�����ҵĿ���5--
					else return false;//���û��5����Ǯ������
				}
				else//���û��10��Ǯ��Ǯ����ֻ����3��5����
				{
					if (five > 3)
					{
						five -= 3;
						continue;//���3����5��Ǯ��Ǯ�����ҵĿ���5-=3
					}
					else return false;//���û�У�����
				}
			}
		}
		return true;
	}
};
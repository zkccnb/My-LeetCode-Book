#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//ʹ����Զ���Ƿ�Χ�ж��Ƿ��ܵ������һ��Ԫ��λ��
//����Զ���Ƿ�Χ���ڿ�������Ծ���κε���һ������Ҫ������������
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int nums_s = nums.size();
		int cover_area = 0;//��Զ�ĸ��Ƿ�Χ
		//����Զ���Ƿ�Χ�ڣ����Ե�������λ�ã����Ǽ�鵱ǰ��Զ���Ƿ�Χ�Ŀ���Ծ���룬�����ɲ����Ը�����Զ���Ƿ�Χ
		for (int i = 0; i <= cover_area; i++) {
			cover_area = max(cover_area, i + nums[i]);
			if (cover_area >= nums_s - 1) return true;
		}
		return false;
	}
};
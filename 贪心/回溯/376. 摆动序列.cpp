#include<iostream>
#include<vector>
#include<algorithm>
//�Ⲣ����̰�ĵ����������ӣ�̰���ǿ��Խ��͸��Ӷȵġ���
//���������д���и������Ǵ�ġ���
using namespace std;
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int maxL = 1;
		bool times = false;
		for (int i = 0; i < nums.size() - 1; i++) {
			times = (nums[i + 1] > nums[i]);
			int cur_i = i;
			int cur_max = 1;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] == nums[cur_i]) continue;
				if ((nums[j] > nums[cur_i]) == times)
				{
					cur_max++;
					cur_i++;
					times = !times;
				}
			}
			maxL = max(maxL, cur_max);
		}
		return maxL;
	}
};
//����һ��ʮ������ķ���������PID�㷨����΢������������Խ�ʱ�临�ӶȽ��͵�O(n)
//���İɣ�����������ô�������벻��������ʵ��һ��̰�ģ��ֲ����Ž����curDiff��preDiff���
//class Solution {
//public:
//	int wiggleMaxLength(vector<int>& nums) {
//		int curDiff = 0, preDiff = 0;
//		int maxL = 1;
//		for (int i = 1; i < nums.size(); i++) {
//			curDiff = nums[i] - nums[i - 1];//���㵱ǰ��ֵ
//			//�����ǰ��ֵ����һ�β�ֵ�����෴��˵�������еĳ���Ӧ�ü�1
//			//ע�⣬���preDiff=0��˵����һ��������һ�������֣�ֻҪ��һ���������ֲ�һ���������г��Ⱦͼ�1
//			if (curDiff < 0 && preDiff >= 0 || curDiff>0 && preDiff <= 0)
//			{
//				maxL++;
//				preDiff = curDiff;//������һ�β�ֵ
//			}
//		}
//		return maxL;
//	}
//};
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//���ѵ�һ���⣡
class Solution {
public:
	int jump(vector<int>& nums) {
		int cur_cover = 0, next_cover = 0;
		int step = 0;
		int nums_s = nums.size();
		for (int i = 0; i < nums_s - 1; i++) {
			next_cover = max(nums[i] + i, next_cover);//������һ�����ǵ���Զ�����Ƕ��٣�һ����һ���ߵ��˸��Ǿ���ı�Ե��׼������cur_cover
			if (i == cur_cover)//�Ѿ��ߵ��˵�ǰ������Զ������±꣬˵����Ҫ����������һ����������cur_cover
			{
				cur_cover = next_cover;
				step++;
			}
		}
		return step;
	}
};
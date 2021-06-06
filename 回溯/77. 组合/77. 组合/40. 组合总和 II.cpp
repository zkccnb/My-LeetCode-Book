#include<iostream>
#include<vector>
#include<algorithm>
//这个题还是很特殊的，需要对遍历到的重复的元素去重；
//这是一种经典的去重逻辑：横向遍历查重而纵向递归不查重（491题的去重逻辑则不一样）
//但是要注意：这个去重只针对每一层横向遍历的元素（每一层横向遍历到的元素不能有相同的）
//纵向递归的时候遍历到的元素可以有重复的！
//纵向递归决定的是当前ret_line中的元素；横向遍历是将这些ret_line放进ret（要是有一样元素的ret_line就错了！）
//之所以要用一个bool型数组去重是因为需要记录数组中当前的元素之前是不是有被横向遍历过
//由于数组已经提前排好序了，重复的元素都在一起，所以只需要检查当前元素的上一个是否被横向遍历过就行了！
using namespace std;
class Solution {
public:
	vector<int> cand;
	int m_target;
	vector<vector<int>> ret;
	vector<int> ret_line;
	vector<bool> isUse;//这个逻辑是：同层遍历，需要检查重复数字，置true；深层递归时，不需要检查重复数字置false！
	int cur_sum;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		cand = candidates;
		sort(cand.begin(), cand.end());//这种做法需要数组有序
		m_target = target;
		vector<bool> use(cand.size(), true);
		isUse = use;
		backtracing(0);
		return ret;
	}
	void backtracing(int cur) {
		if (cur_sum == m_target)
		{
			ret.push_back(ret_line);
			return;
		}
		if (cur_sum > m_target)
		{
			return;
		}
		for (int i = cur; i < cand.size(); i++) {
			//这样意味着本层使用了重复的数字，应该跳过
			if (i > 0 && isUse[i - 1] == true && cand[i] == cand[i - 1]) continue;
			ret_line.push_back(cand[i]);
			cur_sum += cand[i];
			isUse[i] = false;//递归之前把isUse[i]置成false是为了确保向深层遍历的时候，不会因为使用过相同数字而跳过
			backtracing(i + 1);
			isUse[i] = true;//递归返回之后，再把isUse[i]置回true，到时候检查的时候如果有重复的元素就会跳过此元素了
			cur++;
			cur_sum -= cand[i];
			ret_line.pop_back();
		}
	}
};
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
#include<map>
//一道应用题，接近hard级别了！有很多细节，感觉最精髓的是用unordered_map<出发机场, map<降落机场, 出现此种机票的次数>>结构来对出发-降落机场进行映射
//因为需要遍历某个出发机场的全部降落机场，所以这种结构可以很好的完成遍历任务
using namespace std;
class Solution {
public:
	vector<string> ret;
	size_t tickets_s;
	//这里还有一个问题，map的值类型不能用bool，因为测例中会有多个一模一样的机票，就是说映射的标志值并不只有0/1；还可能是很多！
	unordered_map<string, map<string, int>> mp;//出发机场对应了n个降落机场的映射，每个映射对应一个机票（顺便利用map设置了机票是否被纵向遍历过的标志）
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		tickets_s = tickets.size();
		//这个地方容易忽略，要加引用，否则拷贝的元素也不改变原值啊
		for (auto& e_tkt : tickets) {
			mp[e_tkt[0]][e_tkt[1]]++;//初始化映射，同时设置机票的标志
		}
		ret.push_back("JFK");
		backtracking();
		return ret;
	}
	bool backtracking() {
		if (ret.size() == tickets_s + 1) return true;
		//在映射里找当前出发机场对应的所有降落机场
		for (auto& e_pair : mp[ret[ret.size() - 1]]) {//这个地方容易忽略，要加引用，否则拷贝的元素也不改变原值啊
			if (e_pair.second > 0)//当前的机票还没被纵向递归过
			{
				ret.push_back(e_pair.first);//把降落机场加入ret
				e_pair.second--;//标记一下这个机票已经用过了
				if (backtracking()) return true;//如果有一层递归返回值为true，说明已经找到了唯一要求的路径，此时不停向上返回即可
				ret.pop_back();
				e_pair.second++;

			}
		}
		return false;
	}
};
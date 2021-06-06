#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
//思路和135.分发糖果有点像，先按一个维度进行贪心（先按身高从大到小进行排序）；
//再按另一个维度贪心（依次把排好序的元素插入到链表的从前往后数的第k个位置 (k=people[i][1])
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		//先按身高从大到小排序，身高相同的k值小的排在前面
		sort(people.begin(), people.end(), [](vector<int> p1, vector<int> p2) {if (p1[0] == p2[0]) return p1[1] < p2[1]; else return p1[0] > p2[0]; });
		//return people;
		list<vector<int>> people_list;//为了便于插入，在链表里完成后面的操作
		//依次把元素插入到此元素k值对应的链表中的位置
		for (auto r_people : people) {
			int insert_pos = r_people[1];
			auto it = people_list.begin();
			while (insert_pos--) it++;
			people_list.insert(it, r_people);
		}
		//list双向链表，虽然有end()迭代器，但list提供的迭代器是一个双向迭代器，不支持随机访问操作，不支持比较，只能这样遍历了！！
		//int i=0;
		// for(auto r_peolist:people_list){
		//     people[i++]=r_peolist;
		// }
		// return people;
		return vector<vector<int>>(people_list.begin(), people_list.end());
	}
};
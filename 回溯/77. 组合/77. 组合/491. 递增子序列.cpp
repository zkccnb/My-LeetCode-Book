#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
//这个题有很多细节：首先要清楚题目要求，不能对原数组排序，他是要找原数组顺序中是否有递增子序列
//不能按照之前那种去重的方法：设置一个全局重标志，然后纵向递归时不查重，横向遍历时查重
//这个逻辑应该是：每一层需要记录本层当前是否遍历到这个元素，如果遍历到，则过掉；而层和层之间互相独立
//所以明显是每一层建一个哈希表，当遍历到某元素时把该层哈希表的该元素哈希值置位
//最后再注意一下剪枝，没有必要向下遍历时就要及时return
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> ret_line;
    bool isSeq;//当前的line是否为递增的？
    vector<int> m_nums;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        m_nums=nums;
        backtracking(0);
        return ret;
    }
    void backtracking(int cur){
        unordered_map<int,bool> mp;//用来去重：记录出现过的元素；注意，这个哈希表只能是本层可见的！每一层要用一个单独的哈希表，记录本层目前遍历到哪些元素，层之间独立
        isSeq=true;
        if(ret_line.size()>1)
        {
            for(int j=1;j<ret_line.size();j++){
                if(ret_line[j]>=ret_line[j-1]) continue;
                else
                {
                    isSeq=false;
                    break;
                }
            }
            if(isSeq) ret.push_back(ret_line);
            else return;//剪枝，如果此层递归已经不是递增子序列了，就没有必要再向下递归了，在此层横向遍历就行了
        }
        for(int i=cur;i<m_nums.size();i++){
            if(mp[m_nums[i]]==true) continue;
            ret_line.push_back(m_nums[i]);
            mp[m_nums[i]]=true;
            backtracking(i+1);
            ret_line.pop_back();
        }
    }
};
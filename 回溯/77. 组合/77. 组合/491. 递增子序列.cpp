#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<time.h>
#include<unordered_map>
//������кܶ�ϸ�ڣ�����Ҫ�����ĿҪ�󣬲��ܶ�ԭ������������Ҫ��ԭ����˳�����Ƿ��е���������
//���ܰ���֮ǰ����ȥ�صķ���������һ��ȫ���ر�־��Ȼ������ݹ�ʱ�����أ��������ʱ����
//����߼�Ӧ���ǣ�ÿһ����Ҫ��¼���㵱ǰ�Ƿ���������Ԫ�أ�����������������������Ͳ�֮�以�����
//����������ÿһ�㽨һ����ϣ����������ĳԪ��ʱ�Ѹò��ϣ��ĸ�Ԫ�ع�ϣֵ��λ
//�����ע��һ�¼�֦��û�б�Ҫ���±���ʱ��Ҫ��ʱreturn
using namespace std;
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> ret_line;
    bool isSeq;//��ǰ��line�Ƿ�Ϊ�����ģ�
    vector<int> m_nums;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        m_nums=nums;
        backtracking(0);
        return ret;
    }
    void backtracking(int cur){
        unordered_map<int,bool> mp;//����ȥ�أ���¼���ֹ���Ԫ�أ�ע�⣬�����ϣ��ֻ���Ǳ���ɼ��ģ�ÿһ��Ҫ��һ�������Ĺ�ϣ����¼����Ŀǰ��������ЩԪ�أ���֮�����
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
            else return;//��֦������˲�ݹ��Ѿ����ǵ����������ˣ���û�б�Ҫ�����µݹ��ˣ��ڴ˲�������������
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
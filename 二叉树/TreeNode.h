#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<deque>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;
#define null INT_MAX
//********************实现一个便于输出打印并数组构造的树节点类，便于力扣刷树类的题并调试*******************************************************//
class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr), sizeOfTree(0) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), sizeOfTree(0) {}
	TreeNode(int x, TreeNode *theL, TreeNode *theR) : val(x), left(theL), right(theR), sizeOfTree(0) {}
	TreeNode(int* arr, int size);
	inline size_t getSize() { preOrderRecur(this); return sizeOfTree; }//sizeOfTree接口
private:
	int* arrayTree;//数组形式的树
	size_t sizeOfarray;//数组大小
	size_t sizeOfTree;//此节点以下由多少个节点
	size_t m_count;//当前遍历的数组元素个数
	void preOrderRecur(TreeNode* head);
	void preOrderRecur(TreeNode* &head, int num, bool isLeft);
};

ostream& operator<<(ostream& os, TreeNode* root);
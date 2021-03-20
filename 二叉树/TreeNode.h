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
//********************ʵ��һ�����������ӡ�����鹹������ڵ��࣬��������ˢ������Ⲣ����*******************************************************//
class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr), sizeOfTree(0) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), sizeOfTree(0) {}
	TreeNode(int x, TreeNode *theL, TreeNode *theR) : val(x), left(theL), right(theR), sizeOfTree(0) {}
	TreeNode(int* arr, int size);
	inline size_t getSize() { preOrderRecur(this); return sizeOfTree; }//sizeOfTree�ӿ�
private:
	int* arrayTree;//������ʽ����
	size_t sizeOfarray;//�����С
	size_t sizeOfTree;//�˽ڵ������ɶ��ٸ��ڵ�
	size_t m_count;//��ǰ����������Ԫ�ظ���
	void preOrderRecur(TreeNode* head);
	void preOrderRecur(TreeNode* &head, int num, bool isLeft);
};

ostream& operator<<(ostream& os, TreeNode* root);
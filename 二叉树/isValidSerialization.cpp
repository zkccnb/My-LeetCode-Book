#include"TreeNode.h"
//331. 验证二叉树的前序序列化
//用栈的方式验证，但很费时间和空间，可以用一个计数避免建栈，这个题第一次做根本想不到，得看看力扣官方题解才能想到啊！
class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder.size() == 1)
		{
			if (preorder == "#") return true;
			return false;
		}
		stack<string> stk;
		int i = 0;
		string buf;
		while (i < preorder.size()) {
			while (preorder[i] != ',' && i < preorder.size()) buf += preorder[i++];
			i++;
			while (!stk.empty() && buf == "#"&&stk.top() == "#") {
				stk.pop();
				if (!stk.empty()) stk.pop();
				else return false;
			}
			stk.push(buf);
			buf.clear();
		}
		if (stk.size() == 1) return true;
		else return false;
	}
};
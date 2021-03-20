#include"TreeNode.h"
//331. ��֤��������ǰ�����л�
//��ջ�ķ�ʽ��֤�����ܷ�ʱ��Ϳռ䣬������һ���������⽨ջ��������һ���������벻�����ÿ������۹ٷ��������뵽����
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
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//�����ص���dp����ĺ��尡����Զ�̬�滮�ľ��軹�ü�����Ⱑ������
//�о���̬�滮����Сѧ���ҹ�����Ϸһ������
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[2] = 1;
		for (int i = 3; i < n + 1; i++) {
			for (int j = 1; j < i - 1; j++) {
				dp[i] = max(dp[i], max(j*(i - j), j*dp[i - j]));
				//����Ȼ���԰���硣����������������ѭ��������Ҫ�Ƚ����п��ܵļӷ����ܰ�����������ֻ�ǰ����һ���ӷ���ϵ��ɽ���˰�
				//dp[i] = max(j*(i - j), j*dp[i - j]);
			}
		}
		for (int i = 0; i < n + 1; i++) {
			cout << dp[i] << " ";
		}
		cout << endl;
		return dp[n];
	}
};
int main() {
	int ret = Solution().integerBreak(10);
	cout << ret << endl;
}
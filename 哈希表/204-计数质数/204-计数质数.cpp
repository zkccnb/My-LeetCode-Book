#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	int countPrimes_hash(int n) {
		if (n == 0 || n == 1) return 0;
		unordered_set<int> set;
		size_t multi = 2;
		size_t times = multi;
		int i;
		while (multi <= sqrt(n) + 1)
		{
			i = 2;
			while (times < n)
			{
				times = multi * i++;
				if (times <= n) set.insert(times);
				if (set.find(times + multi) != set.end()) times = multi * i++;
			}
			multi++;
			while (set.find(multi) != set.end()) multi++;
			times = multi;
		}
		set.insert(n);
		return (n - set.size() - 1);
	}

	int countPrimes_Eratosthenes(int n) {
		vector<bool> isPrime(n, true);//当数据特别多的时候，用bool比用int节省10M+的空间
		size_t count=0;
		for (auto i = 2; i < n; i++)
		{
			if (isPrime[i]) {
				count++;
				if ((long long int)i*i < n)//这个类型转换很重要，要不大数平方容易超限，long long int是C++可以保留的最大整数范围了
				{
					//埃拉多塞定理：如果把所有质数的整数倍全部排除掉，那么剩下的正整数都是质数
					//另一种描述：所有合数都可以表示成某个质数的整数倍
					for (auto j = i * i; j < n; j += i)
					{
						isPrime[j] = false;
					}
				}
			} 
		}
		return count;
	}
};
int main()
{
	//这个题就是。。。你要是不知道埃拉多塞定理，那么时间上的优化就会很困难
	int a = 999983;
	int count = Solution().countPrimes_Eratosthenes(a);
	/*for (auto it = ret.cbegin(); it != ret.cend(); it++)
	{
		for (auto it1 = it->cbegin(); it1 != it->cend(); it1++)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}*/
	cout << count << endl;
}
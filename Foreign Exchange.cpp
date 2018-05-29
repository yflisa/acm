/*
	交换生现在是很受欢迎的，现在又一个负责这个的组织，经常会收到一大批的申请表， 申请内容是从A国家到B国家的。
	对于一批申请表， 会有各个不同国家申请到另外各个不同的国家， 假设有任意一个申请A到B的，但是没有B到A的申请，
	那么这批申请表都不能被处理。
	样例输入：
	10
	1 2
	2 1
	3 4
	4 3
	100 200
	200 100
	57 2
	2 57
	1 2
	2 1
	10
	1 2
	3 4
	5 6
	7 8
	9 10
	11 12
	13 14
	15 16
	17 18
	19 20
	0
	样例输出
	YES
	NO
*/
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 50000 + 10;
int n;

struct exchange
{
	int a, b;

	bool operator < (const exchange & s) const
	{
		return a < s.a || (a == s.a && b < s.b);
	}
}ex;

set<exchange> group;
bool isExchange = false;

int main()
{
	freopen("data.in", "r", stdin);
	while(cin >> n && n != 0)
	{
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> ex.a >> ex.b;
			if(ex.a > ex.b)
				swap(ex.a, ex.b);
			if(group.count(ex) == 0)
				group.insert(ex);
			else
				group.erase(ex);
		}
		if(group.size() == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
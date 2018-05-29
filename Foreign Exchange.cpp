/*
	�����������Ǻ��ܻ�ӭ�ģ�������һ�������������֯���������յ�һ����������� ���������Ǵ�A���ҵ�B���ҵġ�
	����һ������� ���и�����ͬ�������뵽���������ͬ�Ĺ��ң� ����������һ������A��B�ģ�����û��B��A�����룬
	��ô������������ܱ�����
	�������룺
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
	�������
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
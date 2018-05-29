#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 20;
bool isloop = false;
struct gro
{
	int n;
	int g[maxn];

	void read()
	{
		for(int i = 0; i < n; i++)
			cin >> g[i];
	}
	void change()
	{
		int tmp = g[0];
		for(int i = 0; i < n - 1; i++)
		{
			g[i] = abs(g[i] - g[i+1]);
		}
		g[n-1] = abs(tmp - g[n-1]);
	}
	bool operator < (const gro& b) const
	{
		for(int i = 0; i < n; i++)
			if(g[i] != b.g[i])
				return g[i] < b.g[i];
		return false;
	}
	bool isZero()
	{
		for(int i = 0; i < n; i++)
			if(g[i] != 0)
				return false;
		return true;
	}

}g1;

map<gro, bool> group;

int main()
{
	freopen("data.in", "r", stdin);
	int T;
	cin >> T;
	
	while(T--)
	{
		cin >> g1.n;
		g1.read();
		group.clear();

		group[g1] = true;
		for(int i = 0; i < 1000; i++)
		{
			g1.change();
			if(group[g1] == true)
			{
				isloop = true;
				break;
			}
		}
		if(g1.isZero())
			puts("ZERO");
		else
			puts("LOOP");
		isloop = false;
	}
	return 0;
}
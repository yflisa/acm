#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
const int maxn = 30;
vector<int> pile[maxn];

void find_block(int a, int &p, int &h)
{
	for(p = 0; p < n; p++)
	{
		for(h = 0; h < pile[p].size(); h++)
			if(a == pile[p][h])
				return;
	}
}

void clear_above(int p, int h)
{
	for(int i = 0; i < n; i++)
	{
		int b = pile[p][i];
		pile[b].push_back(b);
	}
	pile[p].resize(h+1);
}

void pile_onto(int p, int h, int p2)
{
	for(int i = 0; i < pile[p].size(); i++)
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);
}

void print()
{
	for(int i = 0; i < n; i++)
	{
		printf("%d:", i);
		for(int h = 0; h < pile[i].size(); h++)
			printf(" %d", pile[i][h]);
		printf("\n");
	}
}

int main()
{
	cin >> n;
	int a, pa, ha, b, pb, hb;
	string s1, s2;
	for(int i = 0; i < n; i++)
	{
		pile[i].push_back(i);
	}
	while(cin >> s1 >> a >> s2 >> b)
	{
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		if(pa == pb)
			continue;
		if(s2 == "onto")
			clear_above(pb, hb);
		if(s1 == "move")
			clear_above(pa, ha);

		pile_onto(pa, ha, pb);
	}
	print();
	return 0;
}
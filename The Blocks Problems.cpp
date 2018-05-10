/*
	题目：
	输入n，得到编号为0~n-1的木块，分别摆放在顺序排列编号为0~n-1的位置。现对这些木块进行操作，操作分为四种。
	1、move a onto b：把木块a、b上的木块放回各自的原位，再把a放到b上；
	2、move a over b：把a上的木块放回各自的原位，再把a发到含b的堆上；
	3、pile a onto b：把b上的木块放回各自的原位，再把a连同a上的木块移到b上；
	4、pile a over b：把a连同a上木块移到含b的堆上。
	当输入quit时，结束操作并输出0~n-1的位置上的木块情况
	样例输入：
	10
	move 9 onto 1
	move 8 over 1
	move 7 over 1
	move 6 over 1
	pile 8 over 6
	pile 8 over 5
	move 2 over 1
	move 4 over 9
	quit
	样例输出：
	 0: 0
 1: 1 9 2 4
 2:
 3: 3
 4:
 5: 5 8 7 6
 6:
 7:
 8:
 9:
*/


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
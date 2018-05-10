/*
	��Ŀ��
	����n���õ����Ϊ0~n-1��ľ�飬�ֱ�ڷ���˳�����б��Ϊ0~n-1��λ�á��ֶ���Щľ����в�����������Ϊ���֡�
	1��move a onto b����ľ��a��b�ϵ�ľ��Żظ��Ե�ԭλ���ٰ�a�ŵ�b�ϣ�
	2��move a over b����a�ϵ�ľ��Żظ��Ե�ԭλ���ٰ�a������b�Ķ��ϣ�
	3��pile a onto b����b�ϵ�ľ��Żظ��Ե�ԭλ���ٰ�a��ͬa�ϵ�ľ���Ƶ�b�ϣ�
	4��pile a over b����a��ͬa��ľ���Ƶ���b�Ķ��ϡ�
	������quitʱ���������������0~n-1��λ���ϵ�ľ�����
	�������룺
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
	���������
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
#include <cstdio>
#include <queue>
#include <string>
#include <map>
using namespace std;
const int maxn = 2000;
int main()
{
	int n, kase = 0;
	FILE* fin = fopen("data.in", "r");
	while(fscanf(fin, "%d", &n) == 1 && n)
	{
		int mbrcnt, member;
		map<int, int > team;
		queue<int> q, q1[maxn];
		printf("Scenario #%d\n", ++kase);
		for(int i = 0; i < n; i++)
		{
			fscanf(fin, "%d", &mbrcnt);
			for(int j = 0; j < mbrcnt; j++)
			{
				fscanf(fin, "%d", &member);
				team[member] = i;
			}
		}
		char cmd[10];
		int seq;
		while(1)
		{
			fscanf(fin, "%s", cmd);
			if(cmd[0] == 'S')
				break;
			else if(cmd[0] == 'D')
			{
				int x = q.front();
				int y = q1[x].front();
				q1[x].pop();
				printf("%d\n", y);
				if(q1[x].empty())
					q.pop();
			}
			else if(cmd[0] == 'E')
			{
				fscanf(fin, "%d", &seq);
				int x = team[seq];
				if(q1[x].empty())
					q.push(x);
				q1[x].push(seq);
			}
		}
		printf("\n");
	}
	return 0;
}
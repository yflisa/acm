/*
	题目：题意：输入建筑物的x,y坐标，宽度，深度和高度，输出从南向北看时能看到的建筑物。

	样例输入：
	14
	160 0 30 60 30
	125 0 32 28 60
	95 0 27 28 40
	70 35 19 55 90
	0 0 60 35 80
	0 40 29 20 60
	35 40 25 45 80
	0 67 25 20 50
	0 92 90 20 80
	95 38 55 12 50
	95 60 60 13 30
	95 80 45 25 50
	165 65 15 15 25
	165 85 10 15 35
	0

	样例输出：
	For map #1, the visible buildings are numbered as follows:
	5 9 4 3 10 2 1 14
*/



#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int n;
double x[maxn * 2];

struct Building
{
	double x, y, w, d, h;
	int id;
	bool operator < (const Building &rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
}b[maxn];

bool cover(int i, double mx)
{
	return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

bool visible(int i, double mx)
{
	if(!cover(i, mx))
		return false;
	for(int k = 0; k < n;k++)
	{
		if(b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx))
			return false;
	}
	return true;
}

int main()
{
	int kase = 0;
	freopen("data.in", "r", stdin);
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 0 ; i < n; i++)
		{
			scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
			x[i*2] = b[i].x;
			x[i*2+1] = b[i].x+b[i].w;
			b[i].id = i + 1;
		}

		sort(b, b + n);
		sort(x, x + 2*n);

		int m = unique(x, x + 2 * n) - x;

		if(kase++)
			printf("\n");
		printf("For map #%d, the visible buildings are numbered as follows:\n%d", kase, b[0].id);
		for(int i = 1; i < n; i++)
		{
			bool vis = false;
			for(int j = 0; j < m-1; j++)
			{
				if(visible(i, (x[j] + x[j+1])/2))
				{
					vis = true;
					break;
				}
			}
			if(vis)
				printf(" %d", b[i].id);
		}
		printf("\n");
	}
	return 0;
}
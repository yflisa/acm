#include <cstdio>
#include <cstring>
const int maxn = 50;
int a[maxn][maxn] = {0};
int main()
{
	int n, x = 0, y = 0, total = 1;
	scanf("%d", &n);
	y = n-1;
	x = 0;
	a[x][y] = total;
	while(total < n*n)
	{
		while(x+1 < n && !a[x+1][y]) a[++x][y] = ++total;
		while(y-1 >= 0  && !a[x][y-1]) a[x][y--] = ++total;
		while(x-1 >= 0  && !a[x-1][y]) a[x--][y] = ++total;
		while(y+1 < n && !a[x][y+1]) a[x][++y] = ++total;
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%3d", a[i][j]);
		printf("\n");
	}
	return 0;
}
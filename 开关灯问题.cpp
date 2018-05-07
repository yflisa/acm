#include <cstdio>
#include <string.h>
const int maxn = 1010;
int a[maxn] = {0};
int main()
{
	int n, k, count = 0;
	scanf("%d%d", &n, &k);
	for(int i = 2; i <= k; i++)
	{
		for(int j = i; j <= n; j += i)
		{
			a[j] = !a[j];
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(!a[i])
		{
			if(i == 1)
				printf("%d", i);
			else
				printf(" %d", i);
		}
	}
	printf("\n");
	return 0;
}
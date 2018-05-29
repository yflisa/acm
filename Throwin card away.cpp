#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> discard;

bool judge()
{
	if(q.size() == 1)
		return true;
	return false;
}
int main()
{
	int n;
	freopen("data.in", "r", stdin);
	while(cin >> n && n != 0)
	{
		q = queue<int>();
		discard.clear();
		for(int i = 1; i <= n; i++)
			q.push(i);
		
		while(1)
		{
			discard.push_back(q.front());
			q.pop();
			//if(judge())
			//	break;
			int tmp = q.front();
			q.push(tmp);
			q.pop();
			if(judge())
				break;
		}
		printf("Discarded cards:%d", discard[0]);
		for(int i = 1; i < discard.size(); i++)
		{
			printf(",%d", discard[i]);
		}
		printf("\nRemaining card:%d\n", q.front());
	}
	return 0;
}
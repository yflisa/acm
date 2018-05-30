#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
int n, m;

int main()
{
	int t;
	freopen("data.in", "r", stdin);
	cin >> t;
	while(t--)
	{
		priority_queue<int, vector<int>, less<int> > pq;
		deque<PII> dq;
		cin >> n >> m;
		int x;
		for(int i = 0; i < n; i++)
		{
			cin >> x;
			pq.push(x);
			dq.push_back(make_pair(x, i));
		}
		int res = 0;
		while(1)
		{
			int top = pq.top();
			pq.pop();
			if(top != dq.front().first)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}

			if(dq.front().second == m)
			{
				res++;
				break;
			}
			else
			{
				res++;
				dq.pop_front();
			}
			
		}
		cout << res << endl;;
	}
	return 0;
}
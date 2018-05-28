#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;
vector<string> charactor[maxn];
int charactor_size[maxn] = {0};

vector<string> words[1010];  
int word_size[200];  

int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.in", "r", stdin);
	string str;
	int idx = 0;
	while(getline(cin, str))
	{
		string tmp;
		stringstream ss(str);
		int cnt = 0;
		while(ss >> tmp)
		{
			charactor[idx].push_back(tmp);
			int len = tmp.size();
			word_size[cnt] = max(word_size[cnt], len);
			cnt++;
		}
		idx++;
	}

	for(int i = 0; i < idx; i++)
	{
		for(int j = 0; j < charactor[i].size(); j++)
		{
			cout << charactor[i][j];
			if(charactor[i][j].size() < word_size[j])
			{
				for(int k = charactor[i][j].size(); k < word_size[j]; k++)
					cout << ' ';
			}
			cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
	string author;
	int status;
};
vector<string> node;
map<string, Node> books;

bool cmp(string a, string b)
{
	if(a != b)
		return a < b;
	else
		return books[a].author < books[b].author;
}

int main()
{
	freopen("data.in", "r", stdin);
	string line;
	while(getline(cin, line) && line != "END")
	{
		string author = line.substr(line.find_first_of("\"")+1);
		string book_name = line.substr(0, line.find_last_of("\"") + 1);
		node.push_back(book_name);
		books[book_name].author = author;
		books[book_name].status = 1;
	}
	sort(node.begin(), node.end(), cmp);
	string centences;
	while(cin >> line)
	{
		if(line == "END")
			break;

		if(line == "BORROW")
		{
			getchar();
			getline(cin, centences);
			books[centences].status = 0;
		}

		if(line == "RETURN")
		{
			getchar();
			getline(cin, centences);
			books[centences].status = -1;
		}

		if(line == "SHELVE")
		{
			for(int i = 0; i < node.size(); i++)
			{
				if(books[node[i]].status == -1)
				{
					int j;
					for(j = i; j >= 0; j--)
					{
						if(books[node[j]].status == 1)
							break;
					}
					if(j > -1)
						cout << "Puts" << node[i] << "after" << node[j] << endl;
					else
						cout << "Puts" << node[i] <<"first" << endl;
					books[node[i]].status  = 1;
				}
			}
			cout << "END" << endl;
		}
	}
	return 0;
}
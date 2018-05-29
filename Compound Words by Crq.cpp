/*
	题意：给出一系列单词，找出由其中两个单词复合组成的单词。
	样例输入：
	a
	alien
	born
	less
	lien
	never
	nevertheless
	new
	newborn
	the
	zebra
	样例输出：
	alien
	newborn
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
set<string> dic;
vector<string> words, result;
int main()
{
	freopen("data.in", "r", stdin);
	string str;
	while(cin >> str)
	{
		dic.insert(str);
		words.push_back(str);
	}

	for(int i = 0; i < words.size(); i++)
	{
		for(int j = 0; j < words.size(); j++)
		{
			string tmp = words[i] + words[j];
			if(dic.count(tmp) != 0)
				result.push_back(tmp);
		}
	}
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}
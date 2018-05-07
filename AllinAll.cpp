#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int len1 = str1.length();
	int len2 = str2.length();
	int count = 0;
	if(len1 > len2)
		printf("No\n");
	int i = 0, j = 0;

	while(i < len1 && j < len2)
	{
		if(str1[i] == str2[j])
		{
			count++;
			i++;
		}
		j++;
	}
	if(count == len1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
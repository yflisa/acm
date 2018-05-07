#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >>str2;
	if(str1.length() < str2.length())
		swap(str1, str2);

	int i = 0, j = 0, start_of_j = j, minlen = 9999;
	bool flag = false;
	while(i < str1.length() && j < str2.length())
	{
		if(str1[i] - '0' + str2[j] - '0' <= 3)
		{
			i++;
			j++;
			flag = true;
		}
		else 
		{
			i = 0;
			start_of_j++;
			j = start_of_j;
			flag = false;
		}
	}

	if(flag == true)
		printf("%d\n", str1.length());
	else
		printf("%d\n", str1.length() + str2.length());
	return 0;
}
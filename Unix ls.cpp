/*
	题目：
	输入正整数n，以及n个文件名，排序后按列有限的方式左对齐输出。假设最长文件名有M字符，则最右列有M字符，其他列都是M+2字符。
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int maxcols = 60;
const int maxn = 100 + 5;
string filenames[maxn];

void print(const string & s, int len, char extra)
{
	cout << s;
	for(int i = 0; i < len-s.length(); i++)
		cout << extra;
}

int main()
{
	int n;
	FILE* fin = freopen("data.in", "r", stdin);
	while(cin >> n)
	{
		int M = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> filenames[i];
			M = max(M, (int)filenames[i].length());
		}
		int cols = (maxcols - M ) / (M + 2) + 1, rows = (n-1) / cols + 1;
		sort(filenames, filenames+n);
		print("", 60, '-');
		cout << "\n";
		for(int r = 0; r < rows; r++)
		{
			for(int c = 0; c < cols; c++)
			{
				int idx = c * rows + r;
				print(filenames[idx], c == cols-1? M:M+2, ' ');
			}
			cout << "\n";
		}
	}
	return 0;
}
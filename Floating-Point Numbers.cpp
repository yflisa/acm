#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	double M[20][40];
	int E[20][40];
	for(int i = 0; i <= 9; i++)
	{
		for(int j = 1; j <= 30; j++)
		{
			double m = 1 - pow(2.0, -1-i);
			double e = pow(2.0, j) - 1;
			double t = log10(m) + e * log10(2.0);
			E[i][j] = t;
			M[i][j] = pow(10, t - E[i][j]);
		}
	}
	string in;
	while(cin >> in && in != "0e0")
	{
		in.replace(in.find('e'), 1, " ");
		istringstream ss(in);
		double A;
		int B;
		ss >> A >> B;
		while(A < 1)
		{
			A *= 10;
			B -= 1;
		}
		for(int i = 0; i <= 9; i++)
		{
			for(int j = 1; j <= 30; j++)
			{
				if(B == E[i][j] && (fabs(A-M[i][j]) < 1e-4 || fabs(A/10-M[i][j]) < 1e-4))
				{
					cout << i << ' ' << j << endl;
					break;
				}
			}
		}
	}
	return 0;
}
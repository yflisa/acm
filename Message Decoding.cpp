#include <cstdio>
#include <cstring>
int code[8][1<<8];

int readchar()
{
	for(;;)
	{
		int ch = getchar();
		if(ch != '\n' || ch != '\r')
			return ch;
	}
}

int readint(int len)
{
	int v = 0;
	while(len--)
	{
		v = v * 2 + readchar() - '0'
	}
	return v;
}

int readcodes()
{
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for(int len = 2; len <= 7; len++)
	{
		for(int i = 0; i < (1<<len-1); i++)
		{
			int ch = getchar();
			if(ch == EOF)
				return 0;
			if(ch == '\r' || ch == '\n')
				return 1;
			code[len][i] = ch;
		}
	}
}

int main()
{
	while(readcodes())
	{
		for(;;)
		{
			int len = readint(3);
			if(len == 0)
				break;
			for(;;)
			{
				int v = readint(len);
				if(v == 1<<len-1)
					break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	return 0;
}
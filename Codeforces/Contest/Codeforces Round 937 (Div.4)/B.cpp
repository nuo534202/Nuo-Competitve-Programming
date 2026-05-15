#include <bits/stdc++.h>
using namespace std;

int n, t;

inline int read()
{
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main()
{
	t = read();
	while (t--)
	{
		n = read();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if ((i + j) % 2 == 0)
					printf("##");
				else
					printf("..");
			}
			printf("\n");
			for (int j = 1; j <= n; j++)
			{
				if ((i + j) % 2 == 0)
					printf("##");
				else
					printf("..");
			}
			printf("\n");
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

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
		a = read(), b = read(), c = read();
		if (c != a + 1)
			printf("%d\n", -1);
		else if (a == 0)
			printf("%d\n", b);
		else if (b == 0)
		{
			int oup = log2(a) + 1;
			printf("%d\n", oup);
		}
		else
		{
			int num = 1, oup = log2(a) + 1, res;
			while (1)
			{
				if (a <= num)
				{
					res = a + num;
					b -= (num - a);
					num *= 2;
					break;
				}
				a -= num;
				num *= 2;
			}
			if (b <= 0)
				printf("%d\n", oup);
			else
				printf("%d\n", oup + (b + res - 1) / res);
		}
	}
	return 0;
}
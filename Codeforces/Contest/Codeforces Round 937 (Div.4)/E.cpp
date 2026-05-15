#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int t, n, ans;
string s1;

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
		ans = n;
		cin >> s1;
		for (int i = 1; i <= n / 2; i++)
		{
			if (n % i != 0)
				continue;
			string s2 = s1.substr(0, i);
			int flag = 0;
			for (int j = 0, k = 0; j < n; j++, k = (k + 1) % i)
			{
				if (s1[j] != s2[k])
					flag++;
				if (flag > 1)
					break;
			}
			if (flag <= 1)
				ans = min(ans, i);
			s2 = s1.substr(n - i, i), flag = 0;
			for (int j = 0, k = 0; j < n; j++, k = (k + 1) % i)
			{
				if (s1[j] != s2[k])
					flag++;
				if (flag > 1)
					break;
			}
			if (flag <= 1)
				ans = min(ans, i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int h, m;
		char c;
		scanf("%d:%d", &h, &m);
		if (h < 12)
		{
			c = 'A';
			if (h == 0)
				h = 12;
		}
		else
		{
			c = 'P';
			if (h != 12)
				h -= 12;
		}
		printf("%02d:%02d %cM\n", h, m, c); // 如果小时或时间为一位数，在前面补零
	}
	return 0;
}
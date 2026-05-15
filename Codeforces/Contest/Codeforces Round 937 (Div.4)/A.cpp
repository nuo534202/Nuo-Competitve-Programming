#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b, c;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c;
		if (a < b && b < c)
			printf("STAIR\n");
		else if (a < b && b > c)
			printf("PEAK\n");
		else
			printf("NONE\n");
	}
	return 0;
}
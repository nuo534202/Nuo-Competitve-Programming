#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	int t = read();
	while (t--) {
		int n = read(), a = read(), b = read(), c = read();
		int ans = n / (a + b + c) * 3;
		n %= (a + b + c);
		if (n > 0) ans++, n -= a;
		if (n > 0) ans++, n -= b;
		if (n > 0) ans++, n -= c;
		printf("%d\n", ans);
	}
	return 0;
}

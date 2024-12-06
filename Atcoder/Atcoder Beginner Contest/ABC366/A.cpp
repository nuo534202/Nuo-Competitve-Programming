#include <bits/stdc++.h>
using namespace std;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
int main() {
	int n = read(), t = read(), a = read();
	if (t > n / 2 || a > n / 2) puts("Yes");
	else puts("No");
	return 0;
}
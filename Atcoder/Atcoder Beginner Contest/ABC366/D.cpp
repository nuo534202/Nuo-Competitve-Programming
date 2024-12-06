#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 105;
int n, q, a[N][N][N], b[N][N], sum[N][N][N];
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
signed main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a[i][j][k] = read();
				b[i][j] += a[i][j][k];
				sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k] + b[i][j];
			}
		}
	}
	q = read();
	while (q--) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read(), l3 = read(), r3 = read();
		l1--, l2--, l3--;
		int ans = sum[r1][r2][r3] - sum[l1][r2][r3] - sum[r1][l2][r3] - sum[r1][r2][l3] + sum[l1][l2][r3] + sum[l1][r2][l3] + sum[r1][l2][l3] - sum[l1][l2][l3];
		printf("%lld\n", ans);
	}
	return 0;
}
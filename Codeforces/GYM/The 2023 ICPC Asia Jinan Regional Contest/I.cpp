#include <bits/stdc++.h>
using namespace std;
 
const int N = 105;
int x[N], y[N], a[N], num = 0;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
signed main() {
	int t = read();
	while (t--) {
		int n = read();
		num = 0;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int l = 1; l <= n; l++) {
			if (a[l] == l) continue;
			for (int r = n; r > l; r--) {
				if (a[l] > a[r]) {
					num++;
					x[num] = l, y[num] = r;
					sort(a + l, a + r + 1);
					break;
				}
			}
		}
		printf("%d\n", num);
		for (int i = 1; i <= num; i++) printf("%d %d\n", x[i], y[i]);
	}
    return 0;
}

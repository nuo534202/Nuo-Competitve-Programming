#include <bits/stdc++.h>
using namespace std;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
bool check(int x) {
	if (x == 2) return false;
	if (x % 2 == 0) return true;
	for (int i = 3; i <= sqrt(x); i++)
		if (x % i == 0) return true;
	return false;
}
 
int main() {
	int t = read(), n, a[1005], ans;
	while (t--) {
		n = read(), ans = -1;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 0; i + j <= n; j++) {
				sum += a[i + j];
                // 检查是否是合数
				if (check(sum)) {
					if (ans == -1) ans = j;
					else ans = min(ans, j);
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

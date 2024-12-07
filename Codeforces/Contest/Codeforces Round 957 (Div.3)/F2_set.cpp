#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, x, a[N];
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int main() {
	t = read();
	while (t--) {
		set<int> s;
		n = read(), x = read();
		int ans = 1;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) {
			if (s.count(a[i])) {
				ans++;
				s.clear();
			}
			if (x % a[i] == 0) {
				for (auto& j : s) if (j % a[i] == 0) s.insert(j / a[i]);
				s.insert(x / a[i]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

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
		map<int, bool> mp;
		n = read(), x = read();
		int ans = 1;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++) {
			if (mp.find(a[i]) != mp.end()) {
				ans++;
				mp.clear();
			}
			if (x % a[i] == 0) {
				for (auto& [j, k] : mp) if (j % a[i] == 0) mp[j / a[i]] = 1;
				mp[x / a[i]] = 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

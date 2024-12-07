#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
signed main() {
	t = read();
	while (t--) {
		n = read();
		string s = to_string(n);
		int len = s.size();
		set<pair<int, int>> ans; // 储存答案
		for (int b = 1; b <= 10000; b++) {
			int x = n, p = 0;
			while (x <= 1000000) {
				if ((to_string(x).size() + b) % len == 0) {
					int a = (to_string(x).size() + b) / len;
					if (a * n - b == x && a <= 10000 && b <= a * n) ans.insert({a, b});
				}
				x = x * 10 + s[p] - '0';
				p = (p + 1) % len;
			}
		}
		printf("%lld\n", ans.size());
		for (auto& val : ans) printf("%lld %lld\n", val.first, val.second);
	}
	return 0;
}
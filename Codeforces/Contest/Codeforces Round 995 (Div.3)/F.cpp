#include <bits/stdc++.h>
using namespace std;

const int Q = 2e5 + 10;
int n, m, q, a;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	int t = read();
	while (t--) {
		n = read(), m = read(), q = read();
		vector<pair<int, int>> v;
		v.push_back({ m, m });
		for (int i = 1; i <= q; i++) {
			a = read();
			vector<pair<int, int>> tmp;
			for (int j = 0; j < v.size(); j++) {
				int l = v[j].first, r = v[j].second;
				if (a < l) tmp.push_back({ l - 1, r });
				else if (a > r) tmp.push_back({ l, r + 1 });
				else {
					tmp.push_back({ 1, 1 }), tmp.push_back({ n, n });
					if (l < r) tmp.push_back({ l, r });
				}
			}
			sort(tmp.begin(), tmp.end());
			v.clear();
			for (int j = 0; j < tmp.size(); j++) {
				if (!j || v.back().second + 1 < tmp[j].first) v.push_back(tmp[j]);
				else v.back().second = max(v.back().second, tmp[j].second);
			}
			int ans = 0;
			for (int j = 0; j < v.size(); j++) ans += v[j].second - v[j].first + 1;
			printf("%d", ans);
			if (i < q) putchar(' ');
		}
		puts("");
	}
	return 0;
}

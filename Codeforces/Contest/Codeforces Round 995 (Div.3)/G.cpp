#include <bits/stdc++.h>
using namespace std;

const int N = 22;
int n, q, e[N], s[N], d[N][N], f[1 << N][N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) d[i][j] = 1;
	for (int _ = 1; _ <= q; _++) {
		int num; char op;
		cin >> num >> op;
		if (op == '+') {
			e[num - 1]++;
			for (int j = 0; j < n; j++) d[num - 1][j] = max(d[num - 1][j], e[num - 1] - s[j] + 1);
		}
		if (op == '-') {
			s[num - 1]++;
			for (int i = 0; i < n; i++) d[i][num - 1] = max(d[i][num - 1], e[i] - s[num - 1] + 1);
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 0; i < n; i++) f[1 << i][i] = 1;
	for (int i = 0; i < 1 << n; i++)
		for (int j = 0; j < n; j++)
			if (i >> j & 1)
				for (int k = 0; k < n; k++)
					if (i >> k & 1)
						f[i][j] = min(f[i][j], f[i - (1 << j)][k] + d[k][j]);
	int ans = 1e9;
	for (int i = 0; i < n; i++)
		ans = min(ans, f[(1 << n) - 1][i] + e[i]);
	cout << ans << '\n';
	return 0;
}

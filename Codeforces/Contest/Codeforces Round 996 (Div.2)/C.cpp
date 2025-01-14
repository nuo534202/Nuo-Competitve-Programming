#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1005;
int n, m, a[N][N], vis[N][N], row[N], col[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		string s;
		cin >> n >> m >> s;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> a[i][j], vis[i][j] = 0;
		vis[1][1] = 1;
		int x = 1, y = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'D') x++;
			if (s[i] == 'R') y++;
			vis[x][y] = i + 2;
		}
		s = " " + s;
		for (int i = 1; i <= n; i++) row[i] = 0;
		for (int j = 1; j <= m; j++) col[j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) row[i] += a[i][j], col[j] += a[i][j];
		int tar = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (vis[i][j]) {
					if (i == n && j == m) a[i][j] = tar - row[i];
					else if (s[vis[i][j]] == 'D') a[i][j] = tar - row[i];
					else a[i][j] = tar - col[j];
					row[i] += a[i][j], col[j] += a[i][j];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << a[i][j];
				if (j < m) cout << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
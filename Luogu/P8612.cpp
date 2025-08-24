#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
int n, m, p, dp[55][55][15][15], w[55][55];

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> w[i][j];
	for (int k = 0; k <= p; k++) {
		for (int c = 0; c <= 12; c++) {
			if (!k) dp[1][1][k][c] = 1;
			else if (k == 1 && c > w[1][1]) dp[1][1][k][c] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k <= p; k++) {
				for (int c = 0; c <= 12; c++) {
					if (i == 1 && j == 1) continue;
					int res1 = dp[i - 1][j][k][c] + dp[i][j - 1][k][c];
					int res2 = 0;
					if (k && c > w[i][j])
						res2 = dp[i - 1][j][k - 1][w[i][j]] + dp[i][j - 1][k - 1][w[i][j]];
					dp[i][j][k][c] = (res1 % mod + res2 % mod) % mod;
				}
			}
		}
	}
	cout << dp[n][m][p][12] << endl;
	return 0;
}

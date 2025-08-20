#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[205][10], n, k;

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i < j) dp[i][j] = 0;
			else if (i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
int n, h[N], dp[N][N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) dp[i][j] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i - j && h[i] != h[i - j]) continue;
			dp[i][j] = max(dp[i][j], dp[i - j][j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) ans = max(ans, dp[i][j]);
	cout << ans << endl;
	return 0;
}

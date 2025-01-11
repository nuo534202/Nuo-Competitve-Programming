#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int k, dp[N][60];
string s, t;

int get(int x, int y) {
	if (abs(x - y) > k) return INT_MAX;
	return dp[x][y - x + 30];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> k >> s >> t;
	memset(dp, 0x3f, sizeof(dp));
	for (int j = 1; j <= k; j++) dp[0][j + 30] = j;
	for (int i = 1; i <= k; i++) dp[i][30 - i] = i;
	dp[0][30] = 0;
	int n = s.size(), m = t.size();
	s = " " + s, t = " " + t;
	for (int i = 1; i <= n; i++) {
		for (int pos = 0; pos < 60; pos++) {
			int j = pos - 30 + i;
			if (j < 1 || j > m) continue;
			int tmp = INT_MAX;
			tmp = min(tmp, get(i - 1, j - 1) + 1);
			tmp = min(tmp, min(get(i - 1, j), get(i, j - 1)) + 1);
			if (s[i] == t[j]) tmp = min(tmp, get(i - 1, j - 1));
			dp[i][pos] = tmp;
		}
	}
	puts(get(n, m) <= k ? "Yes" : "No");
	return 0;
}

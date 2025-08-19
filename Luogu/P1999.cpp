#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
int a, b;

int qpow(int x, int k, int p) {
	int res = 1LL;
	while (k) {
		if (k & 1) res = res * x % p;
		x = x * x % p;
		k >>= 1;
	}
	return res;
}

int C(int n, int m, int p) {
	int up = 1, down = 1;
	for (int i = 1; i <= m; i++) down = down * i % p;
	for (int i = n - m + 1; i <= n; i++) up = up * i % p;
	return up * qpow(down, p - 2, p) % p;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> a >> b;
	if (a < b) {
		cout << 0 << endl;
		return 0;
	}
	int ans = C(a, b, mod) * qpow(2, a - b, mod) % mod;
	cout << ans << endl;
    return 0;
}

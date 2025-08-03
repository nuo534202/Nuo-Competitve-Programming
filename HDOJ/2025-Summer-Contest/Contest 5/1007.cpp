#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int qpow(int x, int k) {
    int res = 1LL;
    while (k) {
        if (k & 1) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int inv(int x, int y) {
    return qpow(y, mod - 2) * x % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << inv(k, n - k + 1) << "\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}

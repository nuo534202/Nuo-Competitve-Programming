#include <bits/stdc++.h>
using namespace std;

#define int long long

using ull = unsigned long long;

const int mod = 998244353;

int qpow(int x, int k, int p) {
    int res = 1LL;
    while (k) {
        if (k & 1) res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res;
}

int inv(int x, int p) {
    return qpow(x, p - 2, p);
}

int p;

void solve() {
    cin >> p;
    int k = (p + 118) / 119;
    if (k >= 23) {
        int tot = qpow(2, k, mod), ans = (p % mod * ((p - 2) % mod) + 2) % mod, res = 0;
        for (int i = (p - 1) / 4 * 4; i < p; i++) res ^= i;
        res %= mod;
        int sumi = (tot + tot * tot % mod) % mod * res % mod;
        ans = (ans + sumi) % mod;
        cout << ans << endl;
    } else {
        ull ans = 0, tot = (1ull << k);
        for (ull i = 1; i < (ull)p; i++) {
            int res = (inv(i, p) + tot) * (i + tot * tot);
            ans ^= res;
        }
        cout << ans % mod << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

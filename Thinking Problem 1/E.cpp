#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

const ll mod = 998244353;
ll n, m, dp[105];

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if (__lg(m) + 1 < n) {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; (1LL << (i - 1)) <= m; i++) {
        ll tmp = ((min(m, (1LL << i) - 1) - (1LL << (i - 1)) + 1) % mod + mod) % mod;
        for (int j = i + 1; j >= 1; j--) dp[j] = (dp[j] + dp[j - 1] * tmp % mod) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}
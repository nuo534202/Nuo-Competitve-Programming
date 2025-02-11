#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int num = min(n / k, m / k);
    if (abs((n - num * k) - (m - num * k)) > k || (n < k && m < k)) {
        cout << -1 << '\n';
        return;
    }
    string ans = "";
    if (n > m) {
        for (int i = 1; i <= k; i++) ans += '0';
        n -= k;
    } else {
        for (int i = 1; i <= k; i++) ans += '1';
        m -= k;
    }
    bool flag = false;
    int tot = min(m, n);
    if (ans.back() == '0') for (int i = 1; i <= tot; i++) ans += "10";
    else for (int i = 1; i <= tot; i++) ans += "01";
    m -= tot, n -= tot;
    if (m > k || n > k) flag = true;
    if (m) for (int i = 1; i <= m; i++) ans += '1';
    else for (int i = 1; i <= n; i++) ans += '0';
    cout << ans << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
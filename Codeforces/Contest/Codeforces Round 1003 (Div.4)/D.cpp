#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> p(n);
    vector<ll> sum(n + 1, 0), score(n + 1), pre(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pre[j] = pre[j - 1] + a[i][j];
            sum[i] += a[i][j];
        }
        ll tot = 0;
        for (int j = 1; j <= m; j++) tot += pre[j];
        score[i] = tot;
    }
    iota(p.begin(), p.end(), 1);
    sort(p.begin(), p.end(), [&](int x, int y){
        return sum[x] > sum[y];
    });
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += (n - i - 1) * m * sum[p[i]] + score[p[i]];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
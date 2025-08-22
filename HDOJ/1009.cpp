#include <bits/stdc++.h>
using namespace std;

int m, n;

void solve() {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end(), [](pair<int, int>& x, pair<int, int>& y){
        return x.second * y.first > y.second * x.first;
    });
    int res = 0;
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (m >= v[i].first) m -= v[i].first, res += v[i].second;
        else if (v[i].first == 0) continue;
        else {
            double a = 1.0 * m / v[i].first;
            ans += a * v[i].second;
            m = 0;
            break;
        }
    }
    cout << fixed << setprecision(3) << ans + res << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    while (1) {
        cin >> m >> n;
        if (m == -1 && n == -1) break;
        solve();
    }
    return 0;
}

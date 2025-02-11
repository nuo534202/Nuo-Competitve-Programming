#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = INT_MIN, a[n + 1] = INT_MAX;
    for (int i = 1; i <= m; i++) cin >> b[i];
    a[1] = min(a[1], b[1] - a[1]);
    for (int i = 2; i <= n; i++) {
        int tar = b[1] - a[i];
        if (a[i - 1] > a[i]) {
            if (a[i - 1] <= tar) a[i] = tar;
            else {
                cout << "NO\n";
                return;
            }
        } else if (a[i - 1] <= tar) a[i] = min(a[i], tar);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] > a[i] || a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a[N];

void solve() {
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], v[a[i]].push_back(i);
    int l = 1, r = n, L = n, R = 1;
    for (int i = 1; i <= n; i++) {
        int x = max(1, i - a[i] + 1), y = min(n, i + a[i] - 1);
        if (x > r || y < l) {
            cout << 0 << "\n";
            return;
        }
        l = max(l, x), r = min(r, y);
        for (int j : v[i]) L = min(L, j), R = max(R, j);
        if (R - L + 1 > i) {
            cout << 0 << '\n';
            return;
        }
    }
    cout << r - l + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
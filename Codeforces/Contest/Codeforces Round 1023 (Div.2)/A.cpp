#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int maxm = 0, minm = INT_MAX;
    for (int i = 1; i <= n; i++)
        maxm = max(maxm, a[i]), minm = min(minm, a[i]);
    if (maxm == minm) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << (1 + (a[i] == maxm)) << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

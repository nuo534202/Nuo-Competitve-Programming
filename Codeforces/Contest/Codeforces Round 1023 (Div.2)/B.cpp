#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;
int n, k, a[N];

void solve() {
    cin >> n >> k;
    int maxm = 0, minm = LLONG_MAX, sum = 0, maxpos = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] > maxm) maxm = a[i], maxpos = i;
    }
    a[maxpos]--;
    maxm = 0, minm = LLONG_MAX;
    for (int i = 1; i <= n; i++)
        maxm = max(maxm, a[i]), minm = min(minm, a[i]);
    if (maxm - minm > k || sum % 2 == 0) cout << "Jerry\n";
    else cout << "Tom\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

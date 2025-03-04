#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int n, x, u[N], d[N];

bool check(int mid) {
    int l = LLONG_MIN, r = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        l = max(l, max(0LL, mid - d[i])), r = min(r, u[i]);
        if (l > r) return false;
        l -= x, r += x;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> x;
    int l = 0LL, r = LLONG_MAX, tar = 0LL;
    for (int i = 1; i <= n; i++) cin >> u[i] >> d[i], r = min(r, u[i] + d[i]);
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, tar = mid;
        else r = mid - 1;
    }
    int ans = 0LL;
    for (int i = 1; i <= n; i++) ans += u[i] + d[i] - tar;
    cout << ans << endl;
    return 0;
}
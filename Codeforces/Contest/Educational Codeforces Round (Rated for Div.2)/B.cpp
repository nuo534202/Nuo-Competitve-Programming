#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int pre[N];

void solve() {
    int n, x, k; string s;
    cin >> n >> x >> k >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++)
        if (s[i] == 'L') pre[i] = pre[i - 1] - 1;
        else pre[i] = pre[i - 1] + 1;
    int num = -1;
    for (int i = 1; i <= n; i++)
        if (pre[i] + x == 0) {
            num = i;
            break;
        }
    int tot = -1;
    for (int i = 1; i <= n; i++)
        if (pre[i] == 0) {
            tot = i;
            break;
        }
    if (num == -1 || k < num) {
        cout << 0 << '\n';
        return;
    }
    k -= num;
    int ans = 1;
    if (tot != -1) ans += k / tot;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
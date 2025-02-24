#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 10;
int a[N], nxt[N][20], f[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n + 1; i++) {
        f[i] = n + 1;
        for (int j = 1; j <= 10; j++) nxt[i][j] = n + 1;
    }
    for (int i = n; i; i--)
        for (int j = 1; j <= 10; j++)
            if (a[i] == j) nxt[i][j] = i;
            else nxt[i][j] = nxt[i + 1][j];
    for (int i = n; i; i--) {
        f[i] = min(f[i], f[i + 1]);
        for (int j = 1; j <= 10; j++) {
            if ((a[i] & 1) != (j & 1)) continue;
            int pos_mid = nxt[i + 1][(a[i] + j) >> 1];
            if (pos_mid > n) continue;
            int pos = nxt[pos_mid + 1][j];
            if (pos > n) continue;
            f[i] = min(f[i], pos);
        }
    }
    ll ans = 0LL;
    for (int i = 1; i <= n; i++) {
        ans += n - f[i] + 1;
    }
    cout << ans << endl;
    return 0;
}
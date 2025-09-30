#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 5, mod = 1e9 + 7;
int n, vis[N];

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        vis[a]++;
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (vis[i] >= 2) {
            for (int j = 1; j <= i / 2; j++) {
                int res;
                if (j == i - j) res = vis[j] * (vis[j] - 1) / 2 % mod;
                else res = vis[j] * vis[i - j] % mod;
                ans = (ans + res * (vis[i] * (vis[i] - 1) / 2) % mod) % mod;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

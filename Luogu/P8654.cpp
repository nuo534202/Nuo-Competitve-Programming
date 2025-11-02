#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, k, f[N], vis[N], ans = 0;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n * m; i++)
        f[i] = i;
    while (k--) {
        int a, b;
        cin >> a >> b;
        f[find(a)] = find(b);
    }
    for (int i = 1; i <= n * m; i++) {
        int x = find(i);
        if (!vis[x]) {
            vis[x] = 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
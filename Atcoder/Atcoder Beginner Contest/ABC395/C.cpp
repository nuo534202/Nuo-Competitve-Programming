#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a[N], maxm = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxm = max(a[i], maxm);
    }
    vector<vector<int>> vis(maxm + 1);
    for (int i = 1; i <= n; i++) vis[a[i]].push_back(i);
    int ans = INT_MAX;
    for (int i = 1; i <= maxm; i++) {
        if (vis[i].size() >= 2) {
            for (int j = 1; j < vis[i].size(); j++)
                ans = min(ans, vis[i][j] - vis[i][j - 1] + 1);
        }
    }
    if (ans != INT_MAX) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}
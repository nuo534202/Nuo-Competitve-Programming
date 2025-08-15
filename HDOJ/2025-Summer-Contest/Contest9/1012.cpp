#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> vis, idx;
    vector<int> v1, v2;
    for (int i = 1; i <= m; i++) {
        int p;
        cin >> p;
        vis[p]++;
        if (vis[p] == 1) v2.push_back(p);
        if (idx.find(p) == idx.end())
            idx[p] = i, v1.push_back(p);
    }
    sort(v2.begin(), v2.end(), [&](int x, int y){
        if (vis[x] == vis[y]) return x < y;
        return vis[x] > vis[y];
    });
    int ans = 0;
    for (int i = 0; i < v1.size(); i++)
        ans += (v1[i] != v2[i]);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

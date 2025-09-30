#include <bits/stdc++.h>
using namespace std;

int n, r;

void dfs(int cur, vector<int>& v, vector<int>& vis) {
    if (cur > r) {
        for (size_t i = 0; i < v.size(); i++)
            cout << setw(3) << v[i];
        cout << '\n';
        return;
    }
    int st;
    if (v.empty()) st = 1;
    else st = v.back() + 1;
    for (int i = st; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1, v.push_back(i);
            dfs(cur + 1, v, vis);
            vis[i] = 0, v.pop_back();
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> r;
    vector<int> v, vis(n + 1);
    dfs(1, v, vis);
    return 0;
}

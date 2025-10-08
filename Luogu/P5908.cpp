#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, d, dis[N], head[N], num = 0;
struct edge { int to, nxt; } e[N << 1];

inline void addEdge(int u, int v) {
    e[++num] = (edge){ v, head[u] }, head[u] = num;
}

void dfs(int u, int fa) {
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        dis[v] = min(dis[u] + 1, dis[v]);
        if (v != fa) dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v), addEdge(v, u);
    }
    dis[1] = 0;
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (dis[i] <= d);
    cout << ans - 1 << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10, M = N << 3;
int n, m, x, head[N << 1], num = 0, dis[N << 1], vis[N << 1] = { 0 };
struct edge { int to, nxt, w; } e[M];
struct node {
    int u, d;
    bool operator< (const node &curNode) const {
        return curNode.d < d;
    }
};

void addEdge(int u, int v, int w) { e[++num] = (edge){ v, head[u], w}, head[u] = num; }

void dijsktra(int s) {
    for (int i = 1; i <= 2 * n; i++) dis[i] = LLONG_MAX;
    dis[s] = 0;
    priority_queue<node> q;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().u; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to, w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({v, dis[v]});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 1), addEdge(v + n, u + n, 1);
    }
    for (int i = 1; i <= n; i++) addEdge(i, i + n, x), addEdge(i + n, i, x);
    dijsktra(1);
    //for (int i = 1; i <= 2 * n; i++) cout << dis[i] << ' '; cout << endl;
    cout << min(dis[n], dis[2 * n]) << endl;
    return 0;
}
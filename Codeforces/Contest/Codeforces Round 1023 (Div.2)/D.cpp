#include <bits/stdc++.h>
using namespace std;

const int N = 150005;
int n, pre[N], used[N], d[N], head[N], num = 0, tar;
struct edge { int to, nxt; } e[N << 1];
array<int, 3> ans[N];

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

void addEdge(int u, int v) { e[++num] = (edge){ v, head[u] }, head[u] = num; }

void dfs(int u, int fa) {
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa || used[v]) continue;
        d[v] = d[u] + 1, pre[v] = u;
        if (d[v] > d[tar] || (d[v] == d[tar] && tar < v)) tar = v;
        dfs(v, u);
    }
}

void solve() {
    n = read();
    for (int i = 1; i <= n; i++) head[i] = used[i] = 0;
    num = 0;
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        addEdge(u, v), addEdge(v, u);
    }
    int m = 0;
    tar = 0;
    while (1) {
        int flag = 0;
        for (int i = 1; i <= n; i++)
            if (!used[i]) { flag = i; break; }
        if (!flag) break;
        d[flag] = 1;
        tar = flag;
        dfs(tar, 0);
        int st = tar;
        d[tar] = 1;
        dfs(tar, 0);
        int ed = tar;
        for (int i = ed; i != st; i = pre[i]) used[i] = 1;
        used[st] = 1;
        ans[++m] = array<int, 3>({ d[ed], max(st, ed), min(st, ed) });
    }
    sort(ans + 1, ans + m + 1, greater<array<int, 3>>());
    for (int i = 1; i <= m; i++) printf("%d %d %d ", ans[i][0], ans[i][1], ans[i][2]);
    putchar('\n');
}

int main() {
    int T = read();
    while (T--) solve();
    return 0;
}

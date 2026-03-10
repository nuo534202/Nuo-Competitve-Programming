#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, head[N], a[N], num = 0;
bool ans[N];
struct edge { int to, nxt; } e[N << 1];

void AddEdge(int u, int v)
{
    e[++num] = { v, head[u] };
    head[u] = num;
}

void dfs(int u, int fa, unordered_map<int, int>& vis)
{
    if (ans[fa] || (vis.find(a[u]) != vis.end() && vis[a[u]] > 0))
        ans[u] = true;
    vis[a[u]]++;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        dfs(v, u, vis);
    }
    vis[a[u]]--;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans[i] = false;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        AddEdge(u, v), AddEdge(v, u);
    }
    unordered_map<int, int> vis;
    dfs(1, 0, vis);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, head[N], num = 0, l = 1, r = 1e9;
struct Edge
{
    int to, nxt, w;
} e[N << 1];
struct Expr
{
    int a, b;
} expr[N];

void addEdge(int u, int v, int w)
{
    e[++num] = (Edge){ v, head[u], w }, head[u] = num;
}

void dfs(int u, int fa)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v != fa)
        {
            expr[v].a = -expr[u].a, expr[v].b = e[i].w - expr[u].b;
            if (expr[v].a > 0)
                l = max(l, (1 - expr[v].b) / expr[v].a);
            else
                r = min(r, (1 - expr[v].b) / expr[v].a);
            dfs(v, u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w), addEdge(v, u, w);
    }
    expr[1] = (Expr){ 1, 0 };
    dfs(1, 0);
    if (l > r)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            cout << expr[i].a * l + expr[i].b << " ";
        }
        cout << "\n";
    }
    return 0;
}
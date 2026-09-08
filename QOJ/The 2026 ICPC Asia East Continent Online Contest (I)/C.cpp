#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5, M = 1e6 + 5;
int n, m, num = 0, head[N], l[M], r[M], q[N], p[N], in[N];
struct Edge { int to, nxt; } e[M];

void addEdge(int u, int v)
{
    e[++num] = (Edge){ v, head[u] };
    head[u] = num, in[v]++;
}

void clear()
{
    for (int i = 1; i <= n; i++)
        head[i] = in[i] = p[i] = 0;
    num = 0;
}

bool topsort()
{
    int cnt = 0;

    priority_queue<int,vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            q.push(i);
            // p[i] = ++cnt;
            // cout << "test: " << i << " " << p[i] << endl;

        }
    }

    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        p[u] = ++cnt;

        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            in[v]--;

            if (!in[v])
            {
                q.push(v);
                // cout << "test: " << v << " " << p[v] << endl;
            }
        }
    }
    if(cnt == n) return true;
    return false;
}

void solve()
{
    cin >> n >> m;
    clear();

    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j <= r[i]; j++)
        {
            cin >> q[j];
            if (j > l[i])
                addEdge(q[j - 1], q[j]);
        }
    }

    if(topsort())
    {
        for (int i = 1; i <= n; i++)
        {
            cout << p[i] << " ";
        }
    }else cout << "-1";

    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
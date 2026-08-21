#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int ans[N];

struct Submit
{
    int a, b, c, pos;
};

struct Ready
{
    int a, b, c, pos;
    bool operator<(const Ready &x) const
    {
        return b > x.b;
    }
};

struct Execute
{
    int a, b, c;
    bool operator<(const Execute &x) const
    {
        return b + c > x.b + x.c;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, queue<Submit>> group_submit;
    unordered_map<int, bool> vis;
    priority_queue<Ready> pq_ready;
    for (int i = 1; i <= m; i++)
    {
        Submit sub;
        Ready ready;
        cin >> sub.a >> sub.b >> sub.c;
        ready.a = sub.a, ready.b = sub.b, ready.c = sub.c;
        sub.pos = ready.pos = i;
        if (vis.find(sub.a) == vis.end())
        {
            pq_ready.push(ready);
            vis[sub.a] = true;
        }
        else
            group_submit[sub.a].push(sub);
    }

    priority_queue<Execute> pq_exec;
    int start = 0;
    while (!pq_exec.empty() || !pq_ready.empty())
    {
        if (!pq_exec.empty() &&
        (static_cast<int>(pq_exec.size()) >= k || pq_ready.empty()))
        {
            Execute cur_exec = pq_exec.top();
            pq_exec.pop();

            start = max(start, cur_exec.b + cur_exec.c);

            if (!group_submit[cur_exec.a].empty())
            {
                Submit sub = group_submit[cur_exec.a].front();
                group_submit[cur_exec.a].pop();

                Ready ready;
                ready.a = sub.a, ready.b = sub.b, ready.c = sub.c, ready.pos = sub.pos;
                pq_ready.push(ready);
            }
        }

        if (pq_ready.empty())
            continue;

        Ready top_ready = pq_ready.top();
        pq_ready.pop();

        Execute next_exec;
        next_exec.a = top_ready.a, next_exec.b = max(top_ready.b, start);
        next_exec.c = top_ready.c;
        pq_exec.push(next_exec);
        ans[top_ready.pos] = next_exec.b;
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
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
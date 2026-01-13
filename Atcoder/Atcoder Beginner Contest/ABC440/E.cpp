#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 55;
int n, k, x, a[N];
struct node
{
    int lstid, cnt, loss;
    bool operator< (const node &x) const
    {
        return loss > x.loss;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int maxm = a[n] * k;
    vector<int> del;
    for (int i = 1; i < n; i++)
        del.push_back(a[n] - a[i]);
    sort(del.begin(), del.end());

    if (n == 1)
    {
        for (int i = 1; i <= x; i++)
            cout << maxm << "\n";
        return 0;
    }

    cout << maxm << "\n";
    x--;

    priority_queue<node> pq;
    pq.push((node){0, 1, del[0]});
    while (x-- && !pq.empty())
    {
        node cur = pq.top();
        pq.pop();
        cout << maxm - cur.loss << "\n";
        if (cur.lstid + 1 < (int)del.size())
            pq.push((node){cur.lstid + 1, cur.cnt, cur.loss - del[cur.lstid] + del[cur.lstid + 1]});
        if (cur.cnt < k)
            pq.push((node){cur.lstid, cur.cnt + 1, cur.loss + del[cur.lstid]});
    }
    return 0;
}
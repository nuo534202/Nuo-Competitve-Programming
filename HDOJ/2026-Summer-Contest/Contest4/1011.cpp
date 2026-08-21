#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, q, a[N];

void solve()
{
    cin >> n >> q;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
    }

    while (q--)
    {
        int r;
        cin >> r;
        if (a[r])
            cout << 0 << "\n";
        else
            cout << sum + 1 << "\n";
    }
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
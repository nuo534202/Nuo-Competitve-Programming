#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int x, y, n, m, a[N], b[N];

void solve()
{
    cin >> x >> y >> n >> m;
    int mina = 0, maxa = 0;
    int minb = 0, maxb = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mina = min(mina, a[i]);
        maxa = max(maxa, a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        minb = min(minb, b[i]);
        maxb = max(maxb, b[i]);
    }

    int ans = LLONG_MIN;
    
    if ((x + maxa) * (y + maxb) > 0 || (x + mina) * (y + minb) > 0)
        ans = max((x + maxa) * (y + maxb), (x + mina) * (y + minb));
    else
        ans = max((x + maxa) * (y + minb), (x + mina) * (y + maxb));

    cout << ans << "\n";
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
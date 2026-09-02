#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int n, a[N], pre[N];

void solve()
{
    cin >> n;
    int ans = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        ans = max(ans, pre[i]);
    }

    int max_pre = 0, drop = 0;
    for (int r = 1; r <= n; r++)
    {
        max_pre = max(max_pre, pre[r - 1]);
        drop = max(drop, max_pre - pre[r - 1]);
        ans = max(ans, pre[r] + drop);
    }

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
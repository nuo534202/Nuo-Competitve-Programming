#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 4e5 + 5;
int n, w, c[N], sum[N], pre[N];

void solve()
{
    cin >> n >> w;
    for (int i = 0; i <= 2 * w; i++)
        sum[i] = pre[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        sum[i % (2 * w) + 1] += c[i];
    }
    for (int i = 1; i <= 2 * w; i++)
        pre[i] = pre[i - 1] + sum[i];
    int ans = LLONG_MAX;
    for (int l = 1; l <= 2 * w; l++)
    {
        int r = l + w - 1;
        if (r > 2 * w)
            r -= 2 * w;
        if (l > r)
            ans = min(ans, pre[2 * w] - pre[l - 1] + pre[r]);
        else
            ans = min(ans, pre[r] - pre[l - 1]);
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
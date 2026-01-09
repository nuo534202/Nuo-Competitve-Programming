#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, k, a[N], b[N], t[N << 1], nxt[N << 1];

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] %= k;
    for (int i = 1; i <= m; i++)
        cin >> b[i], b[i] %= k;
    for (int i = 1; i < m; i++)
        t[i - 1] = (b[i] - b[i + 1] + k) % k;
    t[m - 1] = INT_MAX;
    for (int i = 1; i < n; i++)
        t[i + m - 1] = (a[i + 1] - a[i] + k) % k;
    for (int i = 1; i < n + m; i++)
    {
        int j = nxt[i - 1];
        while (j && t[i] != t[j])
            j = nxt[j - 1];
        if (t[i] == t[j])
            j++;
        nxt[i] = j;
    }
    int ans = 0;
    for (int i = m; i < n + m; i++)
        ans += (nxt[i] == m - 1);
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
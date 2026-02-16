#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), dp(n + 1, inf);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[a[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            dp[j] = min(dp[j], dp[i] + dp[j / i]);

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == inf)
            cout << -1 << " ";
        else
            cout << dp[i] << " ";
    }
    cout << "\n";
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
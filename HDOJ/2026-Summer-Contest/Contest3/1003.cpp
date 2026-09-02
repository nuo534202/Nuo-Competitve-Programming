#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, b, len = 0;
    cin >> n;
    vector<int> dp(63, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> b;
        if (dp[len] <= b)
        {
            dp[len + 1] = dp[len] + b;
            len++;
        }
        for (int j = len; j; j--)
            if (dp[j - 1] <= b)
                dp[j] = min(dp[j], dp[j - 1] + b);
    }
    cout << len << "\n";
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

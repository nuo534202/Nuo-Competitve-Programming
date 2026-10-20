#include <bits/stdc++.h>
using namespace std;

int n, m, a[81];

int main()
{
    cin >> n >> m;

    __int128_t ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[j];

        vector<vector<__int128_t>> dp(m + 2, vector<__int128_t>(m + 2, 0));
        for (int len = 1; len <= m; len++)
        {
            for (int l = 1; l + len - 1 <= m; l++)
            {
                __int128_t pow2 = (__int128_t)1 << (m - len + 1);
                int r = l + len - 1;
                dp[l][r] = max(dp[l + 1][r] + a[l] * pow2, dp[l][r - 1] + a[r] * pow2);
            }
        }

        ans += dp[1][m];
    }

    if (ans == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    string ans_str;
    while (ans)
    {
        ans_str.push_back(ans % 10 + '0');
        ans /= 10;
    }

    reverse(ans_str.begin(), ans_str.end());
    cout << ans_str << endl;

    return 0;
}
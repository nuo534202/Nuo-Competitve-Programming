#include <bits/stdc++.h>
using namespace std;

int m, n, a[51][51], dp[51][51][51][51];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                for (int l = 1; l <= n; l++)
                {
                    if (i == k && j == l) continue;

                    dp[i][j][k][l] = max(
                        max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]),
                        max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])
                    ) + a[i][j] + a[k][l];
                }
            }
        }
    }

    cout << max(dp[m - 1][n][m][n - 1], dp[m][n - 1][m - 1][n]) + a[m][n] << endl;

    return 0;
}
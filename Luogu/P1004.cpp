#include <bits/stdc++.h>
using namespace std;

int n, mp[10][10], dp[10][10][10][10];

int main()
{
    cin >> n;

    memset(dp, 0, sizeof(dp)), memset(mp, 0, sizeof(mp));

    int x, y, v;
    while (true)
    {
        cin >> x >> y >> v;
        if (!x && !y && !v)
            break;
        mp[x][y] = v;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int l = 1; l <= n; l++)
                {
                    int add;
                    if (i == k && j == l)
                        add = mp[i][j];
                    else
                        add = mp[i][j] + mp[k][l];
                    dp[i][j][k][l] = max(dp[i][j][k][l], max({
                        dp[i - 1][j][k - 1][l],
                        dp[i - 1][j][k][l - 1],
                        dp[i][j - 1][k - 1][l],
                        dp[i][j - 1][k][l - 1]})+ add);
                }
            }
        }
    }

    cout << dp[n][n][n][n] << endl;

    return 0;
}
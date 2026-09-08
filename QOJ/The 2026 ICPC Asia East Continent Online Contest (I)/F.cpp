#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 55, M = 20;
int n, m, sum[N], a[N][M], ans = 0;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
        if (sum[i] < sum[i - 1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
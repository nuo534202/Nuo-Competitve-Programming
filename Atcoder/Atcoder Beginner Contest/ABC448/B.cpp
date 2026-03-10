#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        int res = min(c[a - 1], b);
        c[a - 1] -= res, ans += res;
    }
    cout << ans << "\n";
    return 0;
}
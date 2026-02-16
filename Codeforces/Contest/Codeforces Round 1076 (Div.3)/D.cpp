#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
        cin >> b[i], b[i] += b[i - 1];
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = n + 1;
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            if (b[mid] <= n - i + 1) l = mid;
            else r = mid;
        }
        ans = max(ans, l * a[i]);
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
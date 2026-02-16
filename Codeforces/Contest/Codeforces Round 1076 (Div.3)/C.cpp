#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, q, b;
    cin >> n >> q;
    
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b;
        a[i] = max(a[i], b);
    }

    for (int i = n - 1; i; i--)
        a[i] = max(a[i], a[i + 1]);
    
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << " ";
    }
    cout << "\n";
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
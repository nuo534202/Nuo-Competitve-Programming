#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, a[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int cur0 = a[2], cur1 = 0;
    for (int i = 2; i < n; i++)
    {
        int next0 = min(cur0 + a[i + 1], cur1 + max(a[i - 1], a[i + 1]));
        int next1 = min(cur0, cur1 + a[i - 1]);
        cur0 = next0, cur1 = next1;
    }

    cout << min(cur0, cur1 + a[n - 1]) << "\n";
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
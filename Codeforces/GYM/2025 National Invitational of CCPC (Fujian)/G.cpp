#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int a[N], pre[N], n, m, k;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + max(0LL, a[i] - a[i - 1]);
    cin >> k;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << k + pre[r] - pre[l] << "\n";
    }
    return 0;
}
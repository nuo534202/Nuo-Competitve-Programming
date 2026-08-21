#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5, mod = 998244353;
int n, a[N];

int qpow(int x, int k, int p)
{
    int res = 1LL;
    while (k)
    {
        if (k & 1)
            res = res * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return res;
}

int inv(int x, int y, int p)
{
    return x * qpow(y, p - 2, p) % p;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    cout << inv(40, 6, mod) << endl;
    return 0;
}
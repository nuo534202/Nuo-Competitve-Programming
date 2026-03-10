#include <bits/stdc++.h>
using namespace std;

#define int long long

int qpow(int x, int k, int mod)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int n, m, k;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k >> m;
    int mod = 9 * 10007 * m;
    for (int i = 1; i <= k; i++)
    {
        int c, l;
        cin >> c >> l;
        int pw10 = qpow(10, l, mod);
        n = (n * pw10 % mod + (pw10 - 1 + mod) % mod * c % mod) % mod;
    }
    cout << n / m / 9 << "\n";
    return 0;
}
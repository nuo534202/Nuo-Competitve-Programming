#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(int n)
{
    int popcount = 0, res = n;
    while (n)
    {
        if (n & 1)
            popcount++;
        n >>= 1;
    }
    return (popcount * popcount * popcount) == (res >> 1);
}

void solve()
{
    int x;
    cin >> x;

    for (int i = 1; i <= 30; i++)
    {
        int n = 2 * i * i * i;
        if (n >= x && n <= 1000000000 && check(n))
        {
            cout << n << "\n";
            return;
        }

        n++;
        if (n >= x && n <= 1000000000 && check(n))
        {
            cout << n << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}
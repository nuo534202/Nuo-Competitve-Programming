#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int n, a;
    cin >> n;
    int minm = INT_MAX, maxm = 0, mincnt = 0, maxcnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a == minm)
            mincnt++;
        if (a == maxm)
            maxcnt++;
        if (a < minm)
            minm = a, mincnt = 1;
        if (a > maxm)
            maxm = a, maxcnt = 1;
        if (mincnt + maxcnt == i && mincnt == 1 && minm != maxm)
            cout << maxm + maxm << " ";
        else
            cout << minm + maxm << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
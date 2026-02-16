#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s, x, a, sum = 0;
    cin >> n >> s >> x;

    for (int i = 1; i <= n; i++)
        cin >> a, sum += a;
    
    if (s >= sum && (s - sum) % x == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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
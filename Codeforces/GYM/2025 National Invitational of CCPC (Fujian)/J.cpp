#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    while ((n & (-n)) != n)
    {
        v.push_back(n & (-n));
        n += (n & (-n));
    }
    if (((int)log2(n)) & 1)
        v.push_back(n);
    cout << v.size() << "\n";
    for (int i : v)
        cout << i << " ";
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
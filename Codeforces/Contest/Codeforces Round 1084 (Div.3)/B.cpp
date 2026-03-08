#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int maxm = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], maxm = max(maxm, a[i]);
    
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
        {
            flag = false;
        }
    
    if (flag)
        cout << n << "\n";
    else
        cout << 1 << "\n";
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
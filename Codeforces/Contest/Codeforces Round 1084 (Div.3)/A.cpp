#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int>& a)
{
    for (int i : a)
        if (i)
            return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    int maxm = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], maxm = max(maxm, a[i]);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxm)
            ans++;
    }

    cout << ans << "\n";
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
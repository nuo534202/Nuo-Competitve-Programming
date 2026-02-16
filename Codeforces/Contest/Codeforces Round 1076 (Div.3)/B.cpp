#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> v(n), vis(n);
    for (int i = 0; i < n; i++)
        cin >> v[i], vis[v[i] - 1] = i;
    
    int l = n + 1, r = n;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == n - i)
            cout << v[i] << " ";
        else
        {
            l = i, r = vis[n - i - 1];
            break;
        }
    }

    for (int i = r; i >= l; i--)
        cout << v[i] << " ";
    
    for (int i = r + 1; i < n; i++)
        cout << v[i] << " ";
    
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
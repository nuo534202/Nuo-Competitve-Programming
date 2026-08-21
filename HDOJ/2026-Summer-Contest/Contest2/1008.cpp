#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, d[N];

void solve()
{
    cin >> n;
    int mind = INT_MAX, maxd = INT_MIN;
    unordered_map<int, vector<int>> vertex_idx;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        mind = min(mind, d[i]), maxd = max(maxd, d[i]);
        vertex_idx[d[i]].push_back(i);
    }

    bool one_root = (maxd == 2 * mind - 1) && vertex_idx[mind].size() == 1;
    bool two_root = (maxd == 2 * mind - 2) && vertex_idx[mind].size() == 2;
    if (!one_root && !two_root)
    {
        cout << "No\n";
        return;
    }

    for (int i = mind + 1; i <= maxd; i++)
    {
        if (vertex_idx[i].size() < 2)
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    if (one_root)
    {
        if (mind < maxd)
        {
            cout << vertex_idx[mind][0] << " " << vertex_idx[mind + 1][0] << "\n";
            cout << vertex_idx[mind][0] << " " << vertex_idx[mind + 1][1] << "\n";
        }
    }
    else
    {
        cout << vertex_idx[mind][0] << " " << vertex_idx[mind][1] << "\n";

        if (mind < maxd)
        {
            cout << vertex_idx[mind][0] << " " << vertex_idx[mind + 1][0] << "\n";
            cout << vertex_idx[mind][1] << " " << vertex_idx[mind + 1][1] << "\n";
        }
    }

    for (int i = mind + 1; i < maxd; i++)
    {
        cout << vertex_idx[i][0] << " " << vertex_idx[i + 1][0] << "\n";
        cout << vertex_idx[i][1] << " " << vertex_idx[i + 1][1] << "\n";
    }

    for (int i = mind + 1; i <= maxd; i++)
    {
        for (int j = 2; j < static_cast<int>(vertex_idx[i].size()); j++)
        {
            cout << vertex_idx[i - 1][0] << " " << vertex_idx[i][j] << "\n";
        }
    }
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
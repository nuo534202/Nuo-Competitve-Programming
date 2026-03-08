#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, x, y;

void solve()
{
    cin >> n >> x >> y;
    int p;
    vector<int> a, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        if (i <= x || i > y)
            a.push_back(p);
        else
            b.push_back(p);
    }

    int minb = INT_MAX, minb_idx;
    for (size_t i = 0; i < b.size(); i++)
        if (minb > b[i])
            minb = b[i], minb_idx = i;
    
    size_t idxa = 0;
    for (; idxa < a.size(); idxa++)
    {
        if (a[idxa] > minb)
            break;
        cout << a[idxa] << " ";
    }

    for (size_t i = 0; i < b.size(); i++)
    {
        size_t idx = (minb_idx + i) % b.size();
        cout << b[idx] << " ";
    }

    for (;idxa < a.size(); idxa++)
        cout << a[idxa] << " ";
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
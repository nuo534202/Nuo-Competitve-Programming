#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5, K = 10;
int n, q, k, a[N], b[K];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    multiset<int> ms;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ms.insert(a[i]);
    }
    while (q--)
    {
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> b[i];
            auto it = ms.find(a[b[i]]);
            if (it != ms.end())
                ms.erase(it);
        }
        cout << *ms.begin() << "\n";
        for (int i = 1; i <= k; i++)
            ms.insert(a[b[i]]);
    }
    return 0;
}
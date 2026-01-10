#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 3e5 + 5;
int n, q, a[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        int pos = lower_bound(a + 1, a + n + 1, x) - a - 1;
        int l = x, r = INT_MAX;
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            int cnt = lower_bound(a + 1, a + n + 1, mid) - a - 1;
            if (mid - (cnt - pos) - x + 1 > y)
                r = mid;
            else
                l = mid;
        }
        cout << l << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, a[N << 1], odd[N], even[N];

void solve()
{
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        if (i & 1)
            odd[(i + 1) / 2] = odd[(i + 1) / 2 - 1] + a[i];
        else
            even[i / 2] = even[i / 2 - 1] + a[i];
        sum += a[i];
    }

    set<int> st[2];
    int ans = std::abs(odd[n] - even[n]);
    for (int i = 1; i <= 2 * n; i++) {
        int x = odd[n] - even[n] + 2 * (even[i / 2] - odd[(i + 1) / 2]);
        set<int>::iterator it = st[i % 2].lower_bound(x);
        if (it != st[i % 2].end()) {
            ans = min(ans, abs(x - *it));
        }
        if (it != st[i % 2].begin()) {
            ans = min(ans, abs(x - *--it));
        }
        st[i % 2].insert(2 * (even[i / 2] - odd[(i + 1) / 2]));
    }

    cout << (sum - ans) / 2 << "\n";
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
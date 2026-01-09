#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, a[N];

bool check(int x)
{
    vector<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= x)
            st.push_back(1);
        else
            st.push_back(0);
        while (st.size() >= 3 && !st[st.size() - 3] && !st[st.size() - 2])
        {
            st.pop_back();
            st.pop_back();
            st.pop_back();
            st.push_back(0);
        }
    }
    int cnt1 = 0;
    for (int i : st)
        cnt1 += (i == 1);
    return cnt1 * 2 >= (int)st.size();
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = 1000000000, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << "\n";
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
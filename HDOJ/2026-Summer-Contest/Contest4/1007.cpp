#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, d;
    string s;
    cin >> n >> d >> s;

    int g = __gcd(n, 2 * d);
    vector<array<int, 26>> cnt((g + 1) / 2);

    for (int i = 0; i < n; ++i)
    {
        int r = i % g;
        int index = min(r, g - 1 - r);
        cnt[index][s[i] - 'a']++;
    }

    int ans = 0;
    for (array<int, 26>& c : cnt)
    {
        int total = accumulate(c.begin(), c.end(), 0);
        ans += total - *max_element(c.begin(), c.end());
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
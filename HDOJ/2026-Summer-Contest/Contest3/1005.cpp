#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 5;
vector<int> prime;
bool not_prime[N];

void get_prime()
{
    memset(not_prime, false, sizeof(not_prime));
    for (int i = 2; i < N; i++)
    {
        if (!not_prime[i])
            prime.push_back(i);
        for (int j = 0; j < (int)prime.size() && i * prime[j] < N; j++)
        {
            not_prime[i * prime[j]] = true;
            if (i % prime[j])
                break;
        }
    }
}

void solve()
{
    int x;
    cin >> x;

    int ans = 1;
    for (int i : prime)
    {
        int cnt = 0;
        while (x % i == 0)
            cnt++, x /= i;
        ans = max(ans, __lg(cnt) + 1);
    }

    if (x > 1)
    {
        int y = sqrt(x);
        if (y * y == x)
            ans = max(ans, 2LL);
    }
    
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    get_prime();
    while (T--)
        solve();
    return 0;
}
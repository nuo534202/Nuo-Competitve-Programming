#include <bits/stdc++.h>
using namespace std;

#define int long long

const int base1 = 23, mod1 = 1e9 + 7;
const int base2 = 37, mod2 = 998244353;
const int N = 1e6 + 5;

int hash1[N], hash2[N], pw1[N], pw2[N];

#define GET_HASH(hash, pw, l, r, mod) \
    ((hash[r] - hash[l] * pw[r - l] % mod + mod) % mod)

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        hash1[i] = (hash1[i - 1] * base1 % mod1 + s[i]) % mod1;
        hash2[i] = (hash2[i - 1] * base2 % mod2 + s[i]) % mod2;
        pw1[i] = pw1[i - 1] * base1 % mod1;
        pw2[i] = pw2[i - 1] * base2 % mod2;
    }
    int m;
    cin >> m;
    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (GET_HASH(hash1, pw1, l1, r1, mod1) == GET_HASH(hash1, pw1, l2, r2, mod1) &&
            GET_HASH(hash2, pw2, l1, r1, mod2) == GET_HASH(hash2, pw2, l2, r2, mod2))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
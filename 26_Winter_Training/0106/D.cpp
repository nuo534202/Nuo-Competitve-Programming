#include <bits/stdc++.h>
using namespace std;

#define int long long

const int base = 23, mod = 1e9 + 7;
const int N = 1e4 + 5, M = 100;
int n, m, row[N], col[M], nxt[N], pw[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < N; i++)
        pw[i] = pw[i - 1] * base % mod;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            row[i] = (row[i] * base % mod + s[i][j]) % mod;
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            col[j] = (col[j] * base % mod + s[i][j]) % mod;
    for (int i = 1; i < n; i++)
    {
        int j = nxt[i - 1];
        while (j && row[i] != row[j])
            j = nxt[j - 1];
        if (row[i] == row[j])
            j++;
        nxt[i] = j;
    }
    int ans = n - nxt[n - 1];
    for (int i = 1; i < m; i++)
    {
        int j = nxt[i - 1];
        while (j && col[i] != col[j])
            j = nxt[j - 1];
        if (col[i] == col[j])
            j++;
        nxt[i] = j;
    }
    ans *= (m - nxt[m - 1]);
    cout << ans << endl;
    return 0;
}
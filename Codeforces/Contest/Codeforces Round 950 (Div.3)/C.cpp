#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int t, n, m, a[N], b[N], d[N], vis[N];

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}

signed main()
{
    t = read();
    while (t--)
    {
        n = read();
        int flag = 0;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
            b[i] = read();
        m = read();
        for (int i = 1; i <= m; i++)
            d[i] = read();
        int p = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != b[i])
                vis[++p] = b[i];
            if (b[i] == d[m])
                flag = 1;
        }
        sort(d + 1, d + m + 1), sort(vis + 1, vis + p + 1);
        int p1 = 1, p2 = 1;
        while (p1 <= p && p2 <= m)
        {
            if (vis[p1] == d[p2])
                p1++, p2++;
            else
                p2++;
        }
        if (flag && p1 == p + 1)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
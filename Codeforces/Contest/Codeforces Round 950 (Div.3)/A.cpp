#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int t = read();
    while (t--)
    {
        int vis[10];
        memset(vis, 0, sizeof(vis));
        int n = read(), m = read();
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            vis[s[i] - 'A']++;
        int num = 0;
        for (int i = 0; i <= 'G' - 'A'; i++)
        {
            if (vis[i] < m)
                num += m - vis[i]; // 统计个数
        }
        cout << num << endl;
    }
    return 0;
}
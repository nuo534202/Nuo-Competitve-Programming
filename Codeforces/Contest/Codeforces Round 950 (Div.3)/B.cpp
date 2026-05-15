#include <bits/stdc++.h>
using namespace std;

int t, n, f, k, a[105];

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
    t = read();
    while (t--)
    {
        n = read(), f = read(), k = read();
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > a[f])
                num1++;
            else if (a[i] == a[f])
                num2++;
        }
        if (num1 + num2 <= k)
            printf("YES\n");
        else if (num1 >= k)
            printf("NO\n");
        else
            printf("MAYBE\n");
    }
    return 0;
}
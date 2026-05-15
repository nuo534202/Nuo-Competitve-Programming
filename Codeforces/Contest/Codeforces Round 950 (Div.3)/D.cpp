#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int t, n;
vector<int> a(N);

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

int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b % a, a);
}

bool check(int x)
{
    if (x < 0 || x > n - 1)
        return false;
    vector<int> c = a;
    vector<int> d;
    c.erase(c.begin() + x);
    for (int i = 0; i < n - 2; i++)
    {
        d.push_back(gcd(c[i], c[i + 1]));
        if (i && d[i] < d[i - 1])
            return false;
    }
    return true;
}

void solve()
{
    n = read();
    vector<int> b;
    for (int i = 0; i < n; i++)
        a[i] = read();
    for (int i = 0; i < n - 1; i++)
        b.push_back(gcd(a[i], a[i + 1]));
    for (int i = 0; i < n - 2; i++)
    {
        if (b[i] > b[i + 1])
        {
            if (check(i - 1) || check(i) || check(i + 1) || check(i + 2))
                puts("YES");
            else
                puts("NO");
            return;
        }
    }
    puts("YES");
}

int main()
{
    t = read();
    while (t--)
        solve();
    return 0;
}
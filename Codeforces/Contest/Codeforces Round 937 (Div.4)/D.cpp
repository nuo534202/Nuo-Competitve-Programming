#include <bits/stdc++.h>
using namespace std;
 
int t, n, flag;
int a[]={ 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111 };
 
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
        x = x * 10 +c - '0', c = getchar();
    return x * f;
}
 
void dfs(int x)
{
    if (x == 1 || flag == 1)
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < 30; i++)
        if (x % a[i] == 0)
            dfs(x / a[i]);
}
 
 
int main()
{
    t = read();
    while (t--)
    {
        n = read();
        flag = 0;
        dfs(n);
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
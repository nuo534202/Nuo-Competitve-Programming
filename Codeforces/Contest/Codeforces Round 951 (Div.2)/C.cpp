#include<bits/stdc++.h>
using namespace std;

int t, n, k[55], x[55];

#define int long long

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

int lcm(int a, int b) { return a * b / (__gcd(a, b)); }

signed main() {
    t = read();
    while (t--) {
        n = read();
        for (int i = 1; i <= n; i++) k[i] = read();

        int sum = 1, total = 0;

        for (int i = 1; i <= n; i++) {
            sum = lcm(sum, k[i]);
        }

        for (int i = 1; i <= n; i++) total += sum / k[i];

        if (total >= sum) puts("-1");
        else {
            for (int i = 1; i <= n; i++) printf("%d ", sum / k[i]);
            putchar('\n');
        }
    }
    return 0;
}
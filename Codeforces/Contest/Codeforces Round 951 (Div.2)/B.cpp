#include <bits/stdc++.h>
using namespace std;

#define int long long

int t;

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

signed main() {
    t = read();
    while (t--) {
        int x = read(), y = read(), z = x ^ y, ans = 0;
        printf("%lld\n", z & (-z));
    }
    return 0;
}
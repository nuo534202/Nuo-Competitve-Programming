#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 5e5 + 10;
int n, m, a[N], b[N], t[N];
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <='9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
int lowbit(int x) { return x & (-x); }
 
void modify(int x, int k) {
    while (x <= n) {
        t[x] += k;
        x += lowbit(x);
    }
}
 
int query(int x) {
    int oup = 0LL;
    while (x) {
        oup +=t[x];
        x -= lowbit(x);
    }
    return oup;
}
 
signed main() {
    n = read(), m = read();
    for (int i =1; i <= n; i++) {
        a[i] = read();
        b[i] = a[i] - a[i-1];
        modify(i, b[i]);
    }
    while (m--) {
        int opt, x, y, k;
        opt = read();
        if (opt == 1) {
            x = read(), y = read(), k = read();
            modify(x, k), modify(y + 1, -k);
        }
        if (opt == 2) {
            x = read();
            printf("%lld\n", query(x));
        }
    }
    return 0;
}

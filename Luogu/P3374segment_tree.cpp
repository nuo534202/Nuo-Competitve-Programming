#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 5e5 + 10;
int n, m, a[N], t[N], opt, x, y;
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c <'0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c -'0', c = getchar();
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
        oup += t[x];
        x -= lowbit(x);
    }
    return oup;
} // 表示 [1, x] 的和
 
signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        modify(i, a[i]);
    }
    while (m--) {
        opt = read(), x = read(), y = read();
        if (opt == 1) modify(x, y);
        if (opt == 2) printf("%lld\n", query(y) - query(x - 1));
    }
    return 0;
}

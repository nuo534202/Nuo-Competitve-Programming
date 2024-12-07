#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) / 2)
 
const int N = 5e5 + 10;
int n, m, a[N];
struct node { int sum; } t[N << 2];
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
void pushUp(int p) { t[p].sum = t[ls].sum + t[rs].sum; }
 
void build(int p = 1, int l = 1, int  r = n) {
    if (l == r) { t[p].sum = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    pushUp(p);
}
 
void modify(int q, int k, int p = 1, int l = 1, int r = n) {
    if (l == r) { t[p].sum += k; return; }
    if (q <= mid) modify(q, k, ls, l, mid);
    if (q > mid) modify(q, k, rs, mid + 1, r);
    pushUp(p);
}
 
int query(int ql, int qr, int p = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) return t[p].sum;
    int ans = 0LL;
    if (ql <= mid) ans += query(ql, qr, ls, l, mid);
    if (qr > mid) ans += query(ql, qr, rs, mid + 1, r);
    return ans; 
}
 
signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build();
    while (m--) {
        int opt, x, y;
        opt = read(), x = read(), y = read();
        if (opt == 1) modify(x, y);
        else printf("%lld\n", query(x, y));
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
 
const int N = 5e5 + 10;
int n, m, a[N];
struct node { int sum, tag; } t[N << 2];
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >='0' && c <='9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
void pushUp(int p) { t[p].sum = t[ls].sum + t[rs].sum; }
 
void pushDown(int p, int l, int r) {
    if (t[p].tag) {
        t[ls].sum += (mid - l + 1) * t[p].tag, t[rs].sum += (r - mid) * t[p].tag;
        t[ls].tag += t[p].tag, t[rs].tag += t[p].tag;
        t[p].tag = 0;
    }
}
 
void build(int p = 1, int l = 1, int  r = n) {
    if (l == r) { t[p].sum = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    pushUp(p);
}
 
void modify(int ql, int qr, int k, int p = 1, int l = 1, int  r = n) {
    if (ql <= l && r <= qr) {
        t[p].sum += (r - l + 1) * k, t[p].tag += k;
        return;
    }
    pushDown(p, l, r);
    if (ql <= mid) modify(ql, qr, k, ls, l, mid);
    if (qr > mid) modify(ql, qr, k, rs, mid + 1, r);
    pushUp(p);
}
 
int query(int q, int p = 1, int l = 1, int  r = n) {
    if (l == r) return t[p].sum;
    pushDown(p, l, r); int ans = 0LL;
    if (q <= mid) ans += query(q, ls, l, mid);
    if (q > mid) ans += query(q, rs, mid + 1, r);
    return ans;
}
 
signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build();
    while (m--) {
        int opt, x, y, k;
        opt = read(), x = read();
        if (opt == 1) {
            y = read(), k = read();
            modify(x, y, k);
        }
        if (opt == 2) printf("%lld\n", query(x));
    }
    return 0;
}

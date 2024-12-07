#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) / 2)
 
const int N = 1e5 + 10;
int n, q, m, a[N];
struct node { int sum, add, mul; } t[N << 2];
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
void pushUp(int p) { t[p].sum = (t[ls].sum + t[rs].sum) % m; }

void pushDown(int p, int l, int r) {
    t[ls].sum = (t[ls].sum * t[p].mul % m + (mid - l + 1) * t[p].add % m) % m;
    t[rs].sum = (t[rs].sum * t[p].mul % m + (r - mid) * t[p].add % m) % m;
    t[ls].mul = t[ls].mul * t[p].mul % m, t[rs].mul = t[rs].mul * t[p].mul % m;
    t[ls].add = (t[ls].add * t[p].mul % m + t[p].add) % m;
    t[rs].add = (t[rs].add * t[p].mul % m + t[p].add) % m;
    t[p].add = 0LL, t[p].mul = 1LL;
} // 下传延迟标记
 
void build(int p = 1, int l = 1, int r = n) {
    t[p].mul = 1LL; // 任何数乘 1 都不会改变结果，所以初始标记应该为 1
    if (l == r) { t[p].sum = a[l] % m; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    pushUp(p);
}
 
void ad(int ql, int qr, int k, int p = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) {
        t[p].sum = (t[p].sum + (r - l + 1) * k % m) % m;
        t[p].add = (t[p].add + k) % m;
        return;
    }
    pushDown(p, l, r);
    if (ql <= mid) ad(ql, qr, k, ls, l, mid);
    if (qr > mid) ad(ql, qr, k, rs, mid + 1, r);
    pushUp(p);
}
 
void ml(int ql, int qr, int k, int p = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) {
        t[p].sum = t[p].sum * k % m;
        t[p].add = t[p].add * k % m;
        t[p].mul = t[p].mul * k % m;
        return;
    }
    pushDown(p, l, r);
    if (ql <= mid) ml(ql, qr, k, ls, l, mid);
    if (qr > mid) ml(ql, qr, k, rs, mid + 1, r);
    pushUp(p);
}
 
int query(int ql, int qr, int p = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) return t[p].sum % m;
    pushDown(p, l, r); int ans = 0LL;
    if (ql <= mid) ans = (ans + query(ql, qr, ls, l, mid)) % m;
    if (qr > mid) ans = (ans + query(ql, qr, rs, mid + 1, r)) % m;
    return ans % m;
}
 
signed main() {
    n = read(), q = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build();
    while (q--) {
        int opt, x, y, k;
        opt = read(), x = read(), y = read();
        if (opt == 1) { k = read(); ml(x, y, k); }
        if (opt == 2) { k = read(); ad(x, y, k); }
        if (opt == 3) printf("%lld\n", query(x, y));
    }
    return 0;
}

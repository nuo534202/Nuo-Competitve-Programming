#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ls (p << 1) // 左半区间
#define rs (p << 1 | 1) // 右半区间
#define mid ((l + r) / 2)
 
const int N = 1e5 + 10;
int n, m, a[N];
struct node { int sum, tag; } t[N << 2];
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
void pushUp(int p) { t[p].sum = t[ls].sum + t[rs].sum; } // 向上修改线段树
 
void pushDown(int p, int l, int r) {
    t[ls].sum += (mid - l + 1) * t[p].tag, t[rs].sum += (r - mid) * t[p].tag;
    t[ls].tag += t[p].tag, t[rs].tag += t[p].tag;
    t[p].tag = 0;
} // 下传延迟标记
 
void build(int p = 1, int l = 1, int r = n) {
    if (l == r) { t[p].sum = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    pushUp(p);
}
 
void modify(int ql, int qr, int k, int p = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) {
        t[p].sum += (r - l + 1) * k, t[p].tag += k;
        return;
    }
    pushDown(p, l, r);
    if (ql <= mid) modify(ql, qr, k, ls, l, mid);
    if (qr > mid) modify(ql, qr, k, rs, mid + 1, r);
    pushUp(p);
}
 
int query(int ql, int qr, int p = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) return t[p].sum;
    pushDown(p, l, r); int ans = 0LL;
    if (ql <= mid) ans += query(ql, qr, ls, l, mid);
    if (qr > mid) ans += query(ql, qr, rs, mid + 1, r);
    return ans;
}
 
signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build();
    while (m--) {
        int opt, x, y, k;
        opt = read(), x = read(), y = read();
        if (opt ==1) {
            k = read();
            modify(x, y, k);
        }
        else printf("%lld\n", query(x, y));
    }
    return 0;
}

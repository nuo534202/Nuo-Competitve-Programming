#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
 
const int N = 5e5 + 10;
int n, m, a[N];
struct tree { int sum, lm, rm, am; } t[N << 2];
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
void pushUp(int p) {
    t[p].sum = t[ls].sum + t[rs].sum;
    t[p].lm = max(t[ls].lm, t[ls].sum + t[rs].lm), t[p].rm = max(t[rs].rm, t[rs].sum + t[ls].rm);
    t[p].am = max(max(t[ls].am, t[rs].am), t[ls].rm + t[rs].lm);
}
 
void build(int p = 1, int l = 1, int r = n) {
    if (l == r) {
        t[p].sum = t[p].lm = t[p].rm = t[p].am = a[l];
        return;
    }
    build(ls, l, mid), build(rs, mid + 1, r);
    pushUp(p); // 往上修改
}
 
void modify(int q, int k, int p = 1, int l = 1, int r = n) {
    if (l == r) {
        t[p].sum = t[p].lm = t[p].rm = t[p].am = k; // 从最底层开始修改
        return;
    }
    if (q <= mid) modify(q, k, ls, l, mid);
    else modify(q, k, rs, mid + 1, r);
    pushUp(p); // 往上修改
}
 
tree query(int ql, int qr, int p = 1, int l = 1, int r = n) {
    if (ql <= l && r <= qr) return t[p]; // 如果[l,r]是[ql,qr]子区间，直接返回t[p]
    if (qr <= mid) return query(ql, qr, ls, l, mid);
    // 如果[ql,qr]位于[l,r]左半区间，那么直接访问[l,r]左半区间
    else {
        if (ql > mid) return query(ql, qr, rs, mid + 1, r);
        // 如果[ql,qr]位于[l,r]右半区间，那么直接访问[l,r]右半区间
        else {
            tree ans, L = query(ql, qr, ls, l, mid), R = query(ql, qr, rs, mid + 1, r);
            ans.sum = L.sum + R.sum;
            ans.lm = max(L.lm, L.sum + R.lm);
            ans.rm = max(R.rm, R.sum + L.rm);
            ans.am = max(max(L.am, R.am), L.rm + R.lm);
            // 在左半区间和右半区间分别进行查找，之后整合结果
            return ans;
        }
    }
}
 
signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    build();
    while (m--) {
        int k = read(), x = read(), y = read();
        if (k == 1) {
            if (x > y) swap(x, y); // 保证 x <= y
            printf("%lld\n", query(x, y).am);
        }
        else modify(x, y);
    }
    return 0;
}

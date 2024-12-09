#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
 
const int N = 5e5 + 10;
int n;
struct node { int num, pos; } a[N]; // m存读入的数字,num存数字的位置
struct tree { int sum, tag; } t[N << 2];
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
bool cmp(node x, node y) {
    if (x.num == y.num) return x.pos > y.pos;
    return x.num > y.num;
}
 
void pushUp(int p) { t[p].sum = t[ls].sum + t[rs].sum; }
 
void pushDown(int p, int l, int r) {
    if (t[p].tag) {
        t[ls].sum += t[p].tag * (mid - l + 1), t[rs].sum += t[p].tag * (r - mid);
        t[ls].tag += t[p].tag, t[rs].tag += t[p].tag;
        t[p].tag = 0;
    }
}
 
void modify(int q, int k, int p = 1, int l = 1, int r = n) {
    if (l == r) {
        t[p].sum += (mid - l + 1) * k, t[p].tag += k;
        return;
    }
    pushDown(p, l, r);
    if (q <= mid) modify(q, k, ls, l, mid);
    if (q > mid) modify(q, k, rs, mid + 1, r);
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
    n = read();
    for (int i = 1; i <= n; i++) a[i].num = read(), a[i].pos = i;
    sort(a + 1, a + n + 1, cmp);
    int oup = 0LL;
    for (int i = 1; i <= n; i++) {
        oup += query(1, a[i].pos);
        modify(a[i].pos, 1);
    }
    cout << oup << endl;
    return 0;
}

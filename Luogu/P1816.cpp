#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
 
const int N = 1e5 + 10;
int n, m, a[N], t[N << 2];
// 本题的线段树只需要维护区间内的最小值，所以不需要使用结构体数组
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
void pushUp(int p) { t[p] = min(t[ls], t[rs]); }
// 任何一个区间的最小值都是左右儿子最小值中较小的那个
 
void build(int p = 1, int l = 1, int r = n) {
    if (l == r) { t[p] = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    pushUp(p);
}
 
int query(int ql, int qr, int p = 1, int l = 1, int  r = n) {
    if (ql <= l && r <= qr) return t[p];
    int temp = 0xfffffff; // 找左右儿子区间的较小值，temp变量初始化为无穷大
    if (ql <= mid) temp = min(temp, query(ql, qr, ls, l, mid));
    if (qr > mid) temp = min(temp, query(ql, qr, rs, mid + 1, r));
    return temp; // 返回左右儿子区间的较小值
}
 
signed main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    memset(t, 0xfffffff, sizeof(t)); // 由于要维护最小值，t数组初始化为无穷大
    build();
    while (m--) {
        int x = read(), y = read();
        printf("%lld ", query(x, y));
    }
}

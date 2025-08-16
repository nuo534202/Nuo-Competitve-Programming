#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)

const int N = 1e5 + 5;
int n, m, a[N], sum = 0, maxm[N << 2];

void build(int p = 1, int l = 1, int r = n) {
    if (l == r) {
        maxm[p] = a[l], sum += a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ls, l, mid), build(rs, mid + 1, r);
    maxm[p] = max(maxm[ls], maxm[rs]);
}

void modify(int ql, int qr, int p = 1, int l = 1, int r = n) {
    if (maxm[p] <= 2) return;
    if (l == r) {
        sum -= maxm[p] - floor(log2(maxm[p]) + 1);
        maxm[p] = floor(log2(maxm[p]) + 1);
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) modify(ql, qr, ls, l, mid);
    if (qr > mid) modify(ql, qr, rs, mid + 1, r);
    maxm[p] = max(maxm[ls], maxm[rs]);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        modify(l, r);
        cout << sum << "\n";
    }
    return 0;
}

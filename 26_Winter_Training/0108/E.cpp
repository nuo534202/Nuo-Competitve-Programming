#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ls(p) (t[p].lc)
#define rs(p) (t[p].rc)

const int N = 2e5 + 5;
int n, m, a[N], b[N], root[N], cnt = 0;
struct tree { int sum, lc, rc; } t[N << 5];

void build(int &p, int l, int r)
{
    p = ++cnt;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(ls(p), l, mid), build(rs(p), mid + 1, r);
}

void insert(int pv, int &p, int k, int l, int r)
{
    p = ++cnt, t[p] = t[pv], t[p].sum++;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (k <= mid)
        insert(ls(pv), ls(p), k, l, mid);
    else
        insert(rs(pv), rs(p), k, mid + 1, r);
}

int query(int ql, int qr, int k, int l, int r)
{
    if (l == r)
        return l;
    int ls_sum = t[ls(qr)].sum - t[ls(ql)].sum;
    int mid = (l + r) >> 1;
    if (k <= ls_sum)
        return query(ls(ql), ls(qr), k, l, mid);
    else
        return query(rs(ql), rs(qr), k - ls_sum, mid + 1, r);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    int size = unique(b + 1, b + n + 1) - b - 1;
    build(root[0], 1, size);
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = size;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (b[mid] < a[i]) l = mid + 1;
            else r = mid;
        }
        insert(root[i - 1], root[i], l, 1, size);
    }
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << b[query(root[l - 1], root[r], k, 1, size)] << "\n";
    }
    return 0;
}
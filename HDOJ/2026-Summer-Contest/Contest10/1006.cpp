#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)

const int N = 2e5 + 5;
int n, m, a[N];
struct Tree
{
    int num;
    int lval, rval;
    int setTag, revTag;
} tree[N << 2];

void pushUp(int p)
{
    tree[p].num = tree[ls].num + tree[rs].num + (tree[ls].rval ^ tree[rs].lval);
    tree[p].lval = tree[ls].lval, tree[p].rval = tree[rs].rval;
}

void setNode(int p, int k)
{
    tree[p].num = 0;
    tree[p].lval = tree[p].rval = k;
    tree[p].setTag = k;
    tree[p].revTag = 0;
}

void revNode(int p)
{
    tree[p].lval ^= 1, tree[p].rval ^= 1;
    if (tree[p].setTag != -1)
        tree[p].setTag ^= 1;
    else
        tree[p].revTag ^= 1;
}

void pushDown(int p)
{
    if (tree[p].setTag != -1)
    {
        setNode(ls, tree[p].setTag), setNode(rs, tree[p].setTag);
        tree[p].setTag = -1;
    }

    if (tree[p].revTag)
    {
        revNode(ls), revNode(rs);
        tree[p].revTag = 0;
    }
}

void build(int p = 1, int l = 1, int r = n)
{
    tree[p].setTag = -1, tree[p].revTag = 0;
    if (l == r)
    {
        tree[p].num = 0;
        tree[p].lval = tree[p].rval = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    pushUp(p);
}

void modify(int ql, int qr, int k, int p = 1, int l = 1, int r = n)
{
    if (ql <= l && r <= qr)
    {
        setNode(p, k);
        return;
    }

    pushDown(p);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        modify(ql, qr, k, ls, l, mid);
    if (qr > mid)
        modify(ql, qr, k, rs, mid + 1, r);

    pushUp(p);
}

void reverse(int ql, int qr, int p = 1, int l = 1, int r = n)
{
    if (ql <= l && r <= qr)
    {
        revNode(p);
        return;
    }

    pushDown(p);

    int mid = (l + r) >> 1;

    if (ql <= mid)
        reverse(ql, qr, ls, l, mid);
    if (qr > mid)
        reverse(ql, qr, rs, mid + 1, r);

    pushUp(p);
}

Tree query(int ql, int qr, int p = 1, int l = 1, int r = n)
{
    if (ql <= l && r <= qr)
        return tree[p];
    pushDown(p);
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(ql, qr, ls, l, mid);
    if (ql > mid)
        return query(ql, qr, rs, mid + 1, r);

    Tree lans = query(ql, qr, ls, l, mid);
    Tree rans = query(ql, qr, rs, mid + 1, r);
    Tree ans;
    ans.num = lans.num + rans.num + (lans.rval ^ rans.lval);
    ans.lval = lans.lval, ans.rval = rans.rval;
    return ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build();

    while (m--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            int x;
            cin >> x;
            modify(l, r, x);
        }
        else if (op == 2)
        {
            reverse(l, r);
        }
        else
        {
            Tree ans = query(l, r);
            cout << ans.num << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ls (p << 1)
#define rs (p << 1 | 1)
#define int long long

const int N = 2e5 + 5, M = 1e6 + 6, MAXN = 1e6;
int n, q, a[N], b[N];
struct tree { int cnt, sum; } t[M << 2];

void pushUp(int p)
{
    t[p].cnt = t[ls].cnt + t[rs].cnt;
    t[p].sum = t[ls].sum + t[rs].sum;
}

void modify(int pos, int val, int p = 1, int l = 1, int r = MAXN)
{
    if (l == r)
    {
        t[p].cnt += val;
        t[p].sum += pos * val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        modify(pos, val, ls, l, mid);
    else
        modify(pos, val, rs, mid + 1, r);
    pushUp(p);
}

int query(int k, int p = 1, int l = 1, int r = MAXN)
{
    if (k <= 0)
        return 0;
    if (t[p].cnt <= k)
        return t[p].sum;
    if (l == r)
        return k * l;
    int mid = (l + r) >> 1;
    if (k <= t[rs].cnt)
        return query(k, rs, mid + 1, r);
    else
        return t[rs].sum + query(k - t[rs].cnt, ls, l, mid);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    multiset<int> s1, s2;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        if (b[i] == 1)
            s1.insert(a[i]);
        else
            s2.insert(a[i]);
        modify(a[i], 1);
        sum += a[i];
    }
    while (q--)
    {
        int w, x, y;
        cin >> w >> x >> y;

        modify(a[w], -1);
        if (b[w] == 1)
            s1.erase(s1.find(a[w]));
        else
            s2.erase(s2.find(a[w]));
        sum -= a[w];

        a[w] = x, b[w] = y;
        if (b[w] == 1)
            s1.insert(a[w]);
        else
            s2.insert(a[w]);
        modify(a[w], 1);
        sum += a[w];

        if (s2.empty())
        {
            cout << sum << "\n";
        }
        else if (s1.empty())
        {
            cout << 2 * sum - *s2.begin() << "\n";
        }
        else
        {
            int ans = 0;
            if ((*s2.begin()) > (*s1.rbegin()))
                ans = (*s2.begin()) - (*s1.rbegin());
            cout << sum + query(s2.size()) - ans << "\n";
        }
    }
    return 0;
}

/*
4 4
1 2
10 1
3 1
7 2
2 7 1
1 3 1
2 2 1
3 1000000 2
*/

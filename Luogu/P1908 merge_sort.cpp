#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 5e5 + 10;
int n, a[N], b[N], cnt = 0LL;
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
void msort(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) / 2;
    msort(l, mid), msort(mid + 1, r);
    int p1 = l, p2 = mid + 1, p = l;
    while (p1 <= mid || p2 <= r)
        if (p1 > mid) b[p++] = a[p2++];
        else if (p2 > r) b[p++] = a[p1++];
        else if (a[p1] <= a[p2]) b[p++] = a[p2++];
        else {
            b[p++] = a[p1++];
            cnt += (r - p2 + 1); 
            // 若a[p1] > a[p2],a[p1]大于位于p2右边所有的数,
            // 所以p2及其右边所有数的数量就是该层逆序对的数量
        }
    for (int i = l; i <= r; i++) a[i] = b[i];
}
 
signed main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    msort(1, n);
    printf("%lld\n", cnt);
    return 0;
}

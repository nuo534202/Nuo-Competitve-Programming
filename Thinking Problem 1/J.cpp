#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 7e3 + 10;
int n, k, a[N], pos[N], ans[N];

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans[i] = a[i], pos[a[i]] = i;
    int l = 0, r = 0, tot = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        int large = 0, small = 0;
        for (int j = i + 1; j <= n; j++)
            large += (a[j] > a[i]), small += (a[j] < a[i]);
        if (k <= small) {
            sort(a + i + 1, a + n + 1);
            l = i, r = pos[a[i + k]];
            break;
        } else if (k >= tot - large + 1) {
            sort(a + i + 1, a + n + 1);
            int idx = tot - k;
            l = i, r = pos[a[n - idx]];
            break;
        } else
            k -= small;
        tot -= (n - i);
    }
    for (int i = l, j = r; i <= j; i++, j--) swap(ans[i], ans[j]);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << endl;
    return 0;
}
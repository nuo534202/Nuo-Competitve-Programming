#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 105;
int n, k, a[N];

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    __int128_t now = 1;
    int inf = 0;
    for (int i = 1; i <= k; i++) inf = inf * 10 + 9;
    for (int i = 1; i <= n; i++) {
        if (now > inf / a[i]) now = 1;
        else now *= a[i];
    }
    string ans;
    while (now) ans.push_back('0' + now % 10), now /= 10;
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
    cout << endl;
    return 0;
}

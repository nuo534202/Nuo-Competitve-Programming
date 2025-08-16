#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, cnt[N], h[N];

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        for (int j = 1; j <= sqrt(h[i]); j++)
            if (h[i] % j == 0) {
                cnt[j]++;
                if (h[i] / j > j) cnt[h[i] / j]++;
            }
    }
    int res = 1;
    for (int i = N - 1; i; i--) {
        if (cnt[i] >= 3) {
            res = i;
            break;
        }
    }
    sort(h + 1, h + n + 1);
    vector<int> v;
    for (int i = 1; i <= n && v.size() < 3; i++) {
        if (h[i] >= res && h[i] % res == 0)
            v.push_back(h[i]);
    }
    for (int i : v) cout << i << " ";
    cout << endl;
    return 0;
}

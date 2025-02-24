#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), tmp, ans;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) tmp.push_back(a[0] ^ b[i]);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int x : tmp) {
        vector<int> c(n);
        for (int i = 0; i < n; i++) c[i] = a[i] ^ x;
        sort(c.begin(), c.end());
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (b[i] != c[i]) {
                flag = false;
                break;
            }
        if (flag) ans.push_back(x);
    }
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << "\n";
    return 0;
}
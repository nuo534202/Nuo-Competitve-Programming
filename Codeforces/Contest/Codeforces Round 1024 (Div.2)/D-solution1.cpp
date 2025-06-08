#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a, ans[N], t[N];

void add(int x, int k) {
    while (x <= n) {
        t[x] += k;
        x += (x & (-x));
    }
}

int query(int x) {
    int res = 0;
    while (x) {
        res += t[x];
        x -= (x & (-x));
    }
    return res;
}

void solve() {
    cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (i & 1) odd.push_back(a);
        else even.push_back(a);
    }
    for (int i = 0; i <= n; i++) t[i] = 0;
    int num = 0;
    for (int i = odd.size() - 1; i >= 0; i--) {
        num += query(odd[i]);
        add(odd[i], 1);
    }
    for (int i = 0; i <= n; i++) t[i] = 0;
    for (int i = even.size() - 1; i >= 0; i--) {
        num -= query(even[i]);
        add(even[i], 1);
    }
    sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
    for (int i = 0; i < (int)odd.size(); i++) ans[2 * i + 1] = odd[i];
    for (int i = 0; i < (int)even.size(); i++) ans[2 * i + 2] = even[i];
    if (num & 1) swap(ans[n - 2], ans[n]);
    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

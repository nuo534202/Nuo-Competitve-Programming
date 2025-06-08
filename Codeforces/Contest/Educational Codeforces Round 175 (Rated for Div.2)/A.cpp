#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int num = n / 15, ans = 3 * num;
    int res = min(3, n - num * 15 + 1);
    cout << ans + res << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}

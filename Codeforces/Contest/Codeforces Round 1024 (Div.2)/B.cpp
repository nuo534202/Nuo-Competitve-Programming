#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] = abs(a[i]);
    int tot = 1;
    for (int i = 2; i <= n; i++)
        tot += (a[1] <= a[i]);
    if (tot >= (n + 1) / 2) cout <<"YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

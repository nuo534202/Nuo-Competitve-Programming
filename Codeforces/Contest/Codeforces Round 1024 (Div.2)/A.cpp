#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m, p, q, a[N], sum[N];

void solve() {
    cin >> n >> m >> p >> q;
    if (n % p == 0 && n / p * q != m) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

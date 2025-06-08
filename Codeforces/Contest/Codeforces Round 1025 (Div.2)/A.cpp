#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N], n;

void solve() {
    cin >> n;
    int sum0 = 0, sum1 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) sum0++;
        else sum1++;
    }
    bool flag = false;
    for (int i = 1; i < n; i++)
        if (a[i] == 0 && a[i + 1] == 0) flag = true;
    if (!sum0 || !sum1 || flag) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

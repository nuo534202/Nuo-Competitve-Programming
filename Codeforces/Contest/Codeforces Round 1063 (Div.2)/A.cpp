#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i < n; i += 2)
        if (a[i] != a[i + 1]) {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
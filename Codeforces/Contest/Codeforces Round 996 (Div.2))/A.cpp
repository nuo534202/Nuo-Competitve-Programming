#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if ((abs(b - a) - 1) & 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
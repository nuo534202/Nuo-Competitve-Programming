#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    string s, t;
    cin >> n >> s >> t;
    s = " " + s, t = " " + t;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 'A') break;
        if (s[i] == 'A') {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = n; i; i--) {
        if (t[i] == 'B') break;
        if (s[i] == 'B') {
            cout << -1 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += (s[i] != t[i]);
    for (int i = 1, j = 0; i <= n; i++) {
        if (s[i] == t[i]) continue;
        if (t[i] == 'A') j++; // t[i] == 'A' && s[i] == 'B'
        if (t[i] == 'B' && j) ans--, j--;
    }
    cout << ans << endl;
    return 0;
}
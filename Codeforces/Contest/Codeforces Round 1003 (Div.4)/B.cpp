#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int i = 0;
    while (i < s.size() - 1) {
        if (s[i] == s[i + 1]) {
            s.erase(i + 1, 1);
            if (i) s[i] = s[i - 1], i--;
            else if (i + 1 < s.size()) s[i] = s[i + 1];
        } else i++;
    }
    cout << s.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
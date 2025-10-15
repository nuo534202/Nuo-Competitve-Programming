#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> in(n), out(n);
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> out[i];
    stack<int> s;
    int j = 0;
    s.push(in[j++]);
    for (int i = 0; i < n; i++) {
        while ((s.empty() || s.top() != out[i]) && j < n)
            s.push(in[j++]);
        if (s.empty() || s.top() != out[i]) {
            cout << "No\n";
            return;
        }
        s.pop();
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

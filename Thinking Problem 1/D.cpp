#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int pos1[N], pos2[N], cnt1 = 0, cnt2 = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int num1 = 0, num2 = 0;
    for (char c : s) num1 += (c == '1');
    for (char c : t) num2 += (c == '1');
    if (num1 != num2) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') pos1[++cnt1] = i;
        if (t[i] == '0') pos2[++cnt2] = i;
    }
    for (int i = 1; i <= cnt1; i++) ans += (pos1[i] != pos2[i]);
    cout << ans << endl;
    return 0;
}
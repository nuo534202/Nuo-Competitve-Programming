#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, k, a[N];
string s;

bool check(int mid) {
    int num = 0, l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R' && a[i] > mid) {
            if (l <= r) num++;
            l = i + 1, r = i;
        }
        if (s[i] == 'B' && a[i] > mid) {
            r = i;
        }
    }
    num += (l <= r);
    return num <= k;
}

void solve() {
    cin >> n >> k >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
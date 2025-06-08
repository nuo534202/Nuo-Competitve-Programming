#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int step = 0;
    if (n > 1 || m > 1) {
        int tn = min(a, n - a + 1), tm = min(b, m - b + 1);
        if (tn == 0) tn = max(a, n - a);
        if (tm == 0) tm = max(b, m - b);
        if (ceil(log2(m)) + ceil(log2(tn)) <= ceil(log2(tm)) + ceil(log2(n))) n = tn;
        else m = tm;
        step++;
    }
    step += ceil(log2(m)) + ceil(log2(n));
    cout << step << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

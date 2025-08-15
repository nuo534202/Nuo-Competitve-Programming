#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int a[10];
	for (int i = 0; i < 10; i++) cin >> a[i];
	int ans = a[0] + a[4] + a[8], sum = a[1] + a[3] + a[5] + a[7], sum69 = a[6] + a[9];
	if (sum69 >= abs(sum - a[2])) ans += (sum69 + sum + a[2]) / 2;
	else ans += min(sum, a[2]) + sum69;
	cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

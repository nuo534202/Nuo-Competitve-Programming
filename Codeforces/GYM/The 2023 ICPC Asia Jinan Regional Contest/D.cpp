#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int la, lb, ra, rb;
		cin >> la >> lb >> ra >> rb;
		int l = la + ra, r = lb + rb;
		if (r - l >= 10) cout << 9 << '\n';
		else {
			int tmp, ans = 0;
			for (int i = l; i <= r; i++) {
				tmp = i;
				while (tmp) {
					ans = max(ans, tmp % 10);
					tmp /= 10;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}

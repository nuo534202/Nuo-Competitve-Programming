#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, k, l, a[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k >> l;
		for (int i = 1; i <= n; i++) cin >> a[i];
		double ans = a[1], pos = k;
		for (int i = 2; i <= n; i++) {
			if (a[i] - ans > pos) {
				double lpos = pos, lans = ans;
				pos = 1.0 * (a[i] - lans + lpos) / 2 + k;
				ans += 1.0 * (a[i] - lans - lpos) / 2;
			} else {
				pos = min(pos, a[i] + ans) + k;
			}
			if (pos >= l) break;
		}
		if (pos < l) ans += l - pos;
		cout << (int)round(2 * ans) << '\n';
	}
	return 0;
}
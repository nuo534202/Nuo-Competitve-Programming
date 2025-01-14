#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int n, a[N], b[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		int num = 0, pos = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			if (a[i] < b[i]) num++, pos = i;
		}
		if (num > 1) {
			cout << "NO\n";
			continue;
		}
		if (num == 0) {
			cout << "YES\n";
			continue;
		}
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			if (i != pos && a[i] - b[i] < b[pos] - a[pos]) {
				flag = 1;
				break;
			}
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
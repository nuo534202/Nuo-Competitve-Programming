#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
int n, q, a[N], b[N];
vector<int> v;
string s;
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> s;
	int len = s.size();
	s = " " + s;
	for (int i = 1; i <= len; i++) {
		a[i] = a[i - 1] + (s[i] == '1');
		b[i] = b[i - 1] + (s[i] == '2');
		if (s[i] == '/') v.push_back(i);
	}
	while (q--) {
		int l, r, ans = 0; cin >> l >> r;
		int L = lower_bound(v.begin(), v.end(), l) - v.begin();
		int R = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
		while (L <= R) {
			int mid = L + R >> 1;
			int c1 = a[v[mid] - 1] - a[l - 1], c2 = b[r] - b[v[mid]];
			ans = max(ans, 2 * min(c1, c2) + 1);
			if (c1 < c2) L = mid + 1;
			else R = mid - 1;
		}
		cout << ans << '\n';
	}
	return 0;
}

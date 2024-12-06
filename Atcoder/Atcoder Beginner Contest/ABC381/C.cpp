#include <bits/stdc++.h>
using namespace std;
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '/') {
			int l = i, r = i;
			while (l - 1 >= 0 && s[l - 1] == '1') l--;
			while (r + 1 < n && s[r + 1] == '2') r++;
			int res = min(r - i, i - l);
			ans = max(ans, 2 * res + 1);
		}
	}
	cout << ans << endl;
    return 0;
}

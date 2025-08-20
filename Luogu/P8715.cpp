#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int nxt[N], lst[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	unordered_map<char, int> mp;
	for (int i = 1; i <= n; i++) {
		if (mp.find(s[i]) == mp.end()) lst[i] = 0;
		else lst[i] = mp[s[i]];
		mp[s[i]] = i;
	}
	mp.clear();
	for (int i = n; i; i--) {
		if (mp.find(s[i]) == mp.end()) nxt[i] = n + 1;
		else nxt[i] = mp[s[i]];
		mp[s[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (i - lst[i]) * (nxt[i] - i);
	}
	cout << ans << endl;
	return 0;
}

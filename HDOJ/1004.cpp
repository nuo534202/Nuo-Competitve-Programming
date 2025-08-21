#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while (1) {
		cin >> n;
		if (!n) break;
		map<string, int> mp;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			mp[s]++;
		}
		string ans;
		int cnt = 0;
		for (auto& [x, y] : mp) {
			if (y > cnt) ans = x, cnt = y;
		}
		cout << ans << "\n";
	}
	return 0;
}

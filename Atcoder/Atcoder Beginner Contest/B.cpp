#include <bits/stdc++.h>
using namespace std;
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; string s;
	cin >> s;
	n = s.size();
	map<char, int> mp;
	if (n & 1) { cout << "No" << endl; return 0; }
	for (int i = 1; i < n; i += 2) {
		if (s[i] != s[i - 1]) {
			cout << "No" << endl;
			return 0;
		}
		if (mp.find(s[i]) != mp.end()) {
			cout << "No" << endl;
			return 0;
		}
		mp[s[i]] = 2;
	}
	cout << "Yes" << endl;
    return 0;
}

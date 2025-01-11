#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k; string s, t;
	cin >> k >> s >> t;
	if (abs((int)(s.size() - t.size())) > 1) {
		puts("No");
		return 0;
	}
	int l = 0, r = max(t.size(), s.size()) - 1;
	if (t.size() == s.size()) {
		while (l < r && s[l] == t[l]) l++;
		while (l < r && s[r] == t[r]) r--;
	} else if (t.size() > s.size()) {
		while (l < r && s[l] == t[l]) l++;
		while (l < r && s[r - 1] == t[r]) r--;
	} else {
		while (l < r && s[l] == t[l]) l++;
		while (l < r && s[r] == t[r - 1]) r--;
	}
	if (l == r) puts("Yes");
	else puts("No");
    return 0;
}
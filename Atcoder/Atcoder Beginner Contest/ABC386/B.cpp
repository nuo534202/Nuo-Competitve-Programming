#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size(), ans = 0;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] >= '1' && s[i] <= '9') ans++;
		else {
			int j;
			for (j = i; j + 1 <= n && s[j + 1] == '0'; j++);
			ans += (j - i + 2) / 2;
			i = j;
		}
	}
	cout << ans << endl;
    return 0;
}
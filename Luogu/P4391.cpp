#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; string s;
	cin >> n >> s;
	vector<int> nxt(n, 0);
	for (int i = 1; i < n; i++) {
		int j = nxt[i - 1];
		while (j > 0 && s[i] != s[j]) j = nxt[j - 1];
		if (s[i] == s[j]) j++;
		nxt[i] = j;
	}
	cout << n - nxt[n - 1] << '\n';
	return 0;
}

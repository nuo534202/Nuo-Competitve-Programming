#include <bits/stdc++.h>
using namespace std;
 
void solve() {
	string s; cin >> s;
	int size = s.size();
	if (size & 1) {
		puts("No");
		return;
	}
	s = " " + s;
	for (int i = 1; i <= size; i++) {
		if (s[i] == ')') s[i] = '(';
		if (s[i] == ']') s[i] = '[';
	}
	int l = 1, r = size;
	if (s[l] == s[r]) {
		while (l < r && s[l] == s[r]) {
			if (s[l] == s[l - 1]) {
				puts("No");
				return;
			}
			l++, r--;
		}
		if (l < r) puts("No");
		else puts("Yes");
	} else {
		stack<char> st; int flag = 0;
		int i;
		st.push(s[1]); char lst = ' ';
		for (i = 2; i <= size && !st.empty(); i++) {
			if (s[i] == lst) {
				puts("No");
				return;
			}
			if (st.top() != s[i]) {
				st.push(s[i]);
			}
			else {
				lst = st.top();
				st.pop();
			}
		}
		st.push(s[i]);
		i++; lst = ' ';
		for (; i <= size  && !st.empty(); i++) {
			if (s[i] == lst) {
				puts("No");
				return;
			}
			if (st.size() && st.top() != s[i]) {
				st.push(s[i]);
			}
			else {
				lst = st.top();
				st.pop();
			}
		}
		if (i == size + 1 && st.empty()) puts("Yes");
		else puts("No");
	}
}
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
    return 0;
}

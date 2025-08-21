#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s, str;
	cin >> s;
	vector<string> v;
	for (int i = 0; i < (int)s.size(); i++) {
		if (i && s[i] >= 'A' && s[i] <= 'Z') {
			v.push_back(str);
			str = "";
		}
		str += s[i];
	}
	if (str.size()) v.push_back(str);
	int len = 1, n = v.size();
	vector<string> dp(n + 1, "");
	vector<int> pre(n + 1, -1), idx(n + 1, -1);
	dp[1] = v[0], idx[1] = 0;
	for (int i = 1; i < n; i++) {
		if (dp[len] < v[i]) {
			len++;
			dp[len] = v[i], idx[len] = i;
			pre[i] = idx[len - 1];
		}
		else {
			int l = 1, r = len;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (dp[mid] < v[i]) l = mid + 1;
				else r = mid;
			}
			dp[l] = v[i], idx[l] = i;
			pre[i] = idx[l - 1];
		}
	}
	vector<string> ans;
	for (int i = idx[len]; i >= 0; i = pre[i])
		ans.push_back(v[i]);
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
    return 0;
}

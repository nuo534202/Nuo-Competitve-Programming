#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, x, y;
set<pair<int, int>> vis;
vector<pair<int, int>> vx, vy;

bool cmp(const pair<int, int> &px, const pair<int, int> &py) {
	return px.first < py.first || (px.first == py.first && px.second < py.second);
}

pair<int, int> find(int fi, int sel, int ser, const vector<pair<int, int>> &v) {
	int L = lower_bound(v.begin(), v.end(), make_pair(fi, sel), cmp) - v.begin();
	int R = upper_bound(v.begin(), v.end(), make_pair(fi, ser), cmp) - v.begin() - 1;
	return {L, R};
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++) {
		int xx, yy;
		cin >> xx >> yy;
		vx.push_back({xx, yy}), vy.push_back({yy, xx});
	}
	sort(vx.begin(), vx.end()), sort(vy.begin(), vy.end());
	while (m--) {
		char op; int c;
		cin >> op >> c;
		if (op == 'U') {
			pair<int, int> ans = find(x, y, y + c, vx);
			for (int i = ans.first; i <= ans.second; i++) vis.insert(vx[i]);
			y += c;
		}
		if (op == 'D') {
			pair<int, int> ans = find(x, y - c, y, vx);
			for (int i = ans.first; i <= ans.second; i++) vis.insert(vx[i]);
			y -= c;
		}
		if (op == 'L') {
			pair<int, int> ans = find(y, x - c, x, vy);
			for (int i = ans.first; i <= ans.second; i++) vis.insert({vy[i].second, vy[i].first});
			x -= c;
		}
		if (op == 'R') {
			pair<int, int> ans = find(y, x, x + c, vy);
			for (int i = ans.first; i <= ans.second; i++) vis.insert({vy[i].second, vy[i].first});
			x += c;
		}
	}
	cout << x << ' ' << y << ' ' << vis.size() << endl;
	return 0;
}

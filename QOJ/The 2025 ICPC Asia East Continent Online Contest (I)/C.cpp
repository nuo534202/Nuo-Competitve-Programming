#include <bits/stdc++.h>
using namespace std;

const int M = 2e5 + 5;
pair<int, int> p[M];

void solve() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		cin >> p[i].first >> p[i].second;
	sort(p + 1, p + m + 1);
	int ans = 0, lst = 0, i = 1;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (i <= m) {
		lst = p[i].first;
		while (1) {
			while (i <= m && p[i].first <= lst) {
				if (lst < p[i].second)
					pq.push(p[i].second);
				i++;
			}
			if (pq.empty()) break;
			lst++, ans++, pq.pop();
			while (!pq.empty() && lst >= pq.top())
				pq.pop();
		}
	}
	cout << n - ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}

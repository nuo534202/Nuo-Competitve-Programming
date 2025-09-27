#include <bits/stdc++.h>
using namespace std;

const int N = 505, dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int n, m, a, b, t[N][N];
queue<pair<int, int>> q;
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			t[i][j] = INT_MAX;
	for (int i = 1; i <= a; i++) {
		int x, y;
		cin >> x >> y;
		q.push({x, y});
		t[x][y] = 0;
	}
	for (int i = 1; i <= b; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (t[nx][ny] > t[x][y] + 1) {
				t[nx][ny] = t[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	for (const pair<int, int>& p : v) {
		cout << t[p.first][p.second] << endl;
	}
	return 0;
}

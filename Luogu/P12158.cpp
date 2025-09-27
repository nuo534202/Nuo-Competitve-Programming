#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, vis[N];
double dis[N];
struct pt { int x, y, r; } e[N];
priority_queue<pair<double, int>> pq; 

double getDis(int i, int j) {
	int dx = e[i].x - e[j].x, dy = e[i].y - e[j].y;
	int dr = e[i].r + e[j].r;
	if (dx * dx + dy * dy <= dr * dr) return 0.0;
	return sqrt(1.0 * dx * dx + dy * dy) - dr;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> e[i].x >> e[i].y >> e[i].r, dis[i] = 1e9;
	double ans = 0.0;
	dis[1] = 0;
	while (1) {
		int pos = -1;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && (pos == -1 || dis[pos] > dis[i]))
				pos = i;
		if (pos == -1) break;
		ans += dis[pos];
		vis[pos] = 1;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dis[i] = min(dis[i], getDis(i, pos));
	}
	cout << fixed << setprecision(2) << ans << '\n';
	return 0;
}

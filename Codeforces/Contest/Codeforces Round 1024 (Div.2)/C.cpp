#include <bits/stdc++.h>
using namespace std;

constexpr int N = 505;
int n, a[N][N], cnt = 0;
constexpr int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) a[i][j] = 0;
	cnt = 1;
	int step = 1, d = 0;
	int x = (n + 1) / 2, y = (n + 1) / 2;
	while (cnt < n * n) {
		for (int i = 1; i <= step; i++) {
			x += dx[d], y += dy[d];
			a[x][y] = cnt++;
		}
		d = (d + 1) % 4;
		if (d == 0 || d == 2) step++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
		cout << "\n";
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

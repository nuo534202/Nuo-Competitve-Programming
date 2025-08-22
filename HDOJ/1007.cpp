#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, ansa, ansb;
double mindis;
struct pt { double x, y; int id; } p[N], t[N];

void update_ans(const pt& a, const pt& b) {
	double dis = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	if (mindis > dis) mindis = dis, ansa = a.id, ansb = b.id;
}

bool cmpx(const pt& a, const pt& b) {
	return a.x < b.x;
}

bool cmpy(const pt& a, const pt& b) {
	return a.y < b.y;
}

void rec(int l, int r) {
	if (r - l <= 3) {
		for (int i = l; i <= r; i++)
			for (int j = i + 1; j <= r; j++) update_ans(p[i], p[j]);
		sort(p + l, p + r + 1, cmpy);
		return;
	}

	int mid = (l + r) >> 1, midx = p[mid].x;
	rec(l, mid), rec(mid + 1, r);
	inplace_merge(p + l, p + mid + 1, p + r + 1, cmpy);

	int cnt = 0;
	for (int i = l; i <= r; i++)
		if (abs(p[i].x - midx) < mindis) {
			for (int j = cnt; j && p[i].y - t[j].y < mindis; j--)
				update_ans(p[i], t[j]);
			t[++cnt] = p[i];
		}
}

void solve() {
	for (int i = 1; i <= n; i++)
		cin >> p[i].x >> p[i].y, p[i].id = i;
	mindis = 1e9, ansa = ansb = 0;
	sort(p + 1, p + n + 1, cmpx);
	rec(1, n);
	cout << fixed << setprecision(2) << mindis / 2 << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		cin >> n;
		if (!n) break;
		solve();
	}
	return 0;
}

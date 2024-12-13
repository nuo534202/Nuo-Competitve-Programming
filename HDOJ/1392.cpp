#include<bits/stdc++.h>
using namespace std;

struct point {
	double x, y, ang;
	point operator-(const point &p) const { return { x - p.x, y - p.y, 0.0 }; }
} p[105];

double dis(point p1, point p2) { return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); }

bool cmp(point p1, point p2) {
	if (p1.ang == p2.ang) return dis(p1, p[1]) < dis(p2, p[1]);
	return p1.ang < p2.ang;
}

double cross(point p1, point p2) { return p1.x * p2.y - p1.y * p2.x; }

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	while (1) {
		cin >> n;
		if (!n) break;
		for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
		for (int i = 2; i <= n; i++)
			if (p[i].y < p[1].y || (p[i].y == p[1].y && p[i].x < p[1].x)) swap(p[1], p[i]);
		for (int i = 2; i <= n; i++) p[i].ang = atan2(p[i].y - p[1].y, p[i].x - p[1].x);
		sort(p + 2, p + n + 1, cmp);
		int st[105], top = 0;
		st[++top] = 1;
		for (int i = 2; i <= n; i++) {
			while (top >= 2 && cross(p[st[top]] - p[st[top - 1]], p[i] - p[st[top]]) < 0) top--;
			st[++top] = i;
		}
		double ans = 0;
		for (int i = 2; i <= top; i++) ans += dis(p[st[i]], p[st[i - 1]]);
		if (n > 2) ans += dis(p[st[1]], p[st[top]]);
		cout << fixed << setprecision(2) << ans << '\n';
	}
	return 0;
}

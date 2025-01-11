#include <bits/stdc++.h>
using namespace std;

const int M = 2e5 + 10;
int n, m;
struct node { int x, y; char c; } p[M];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> p[i].x >> p[i].y >> p[i].c;
	sort(p + 1, p + m + 1, [](const node &a, const node &b){
		if (a.x == b.x) return a.c > b.c;
		return a.x < b.x;
	});
	n++;
	for (int i = 1; i <= m; i++) {
		if (p[i].c == 'W') n = min(n, p[i].y);
		if (p[i].c == 'B') {
			if (p[i].y >= n) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
    return 0;
}
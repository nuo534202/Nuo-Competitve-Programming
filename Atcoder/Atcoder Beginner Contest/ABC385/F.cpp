#include <bits/stdc++.h>
using namespace std;

#define double long double

const int N = 2e5 + 10;
int n;
double x[N], h[N], ans = 0.0;
bool ok = false;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> h[i];
	for (int i = 2; i <= n; i++) {
		double d = h[i - 1] - (h[i] - h[i - 1]) / (x[i] - x[i - 1]) * x[i - 1];
		if (d >= 0) ok = true;
		ans = max(ans, d);
	}
	if (ok) cout << fixed << setprecision(10) << ans << endl;
	else cout << -1 << endl;
	return 0;
}

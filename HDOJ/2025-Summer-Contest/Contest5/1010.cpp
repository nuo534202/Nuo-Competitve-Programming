#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, x[N];
double f[N], p[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i], p[i] = 1.0 * x[i] / 1000;
	f[n] = n;
	for (int i = n - 1; i; i--)
		f[i] = min(f[i + 1], (1.0 - p[i]) * i + p[i] * (f[i + 1] + 20));
	cout << fixed << setprecision(9) << f[1] << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}

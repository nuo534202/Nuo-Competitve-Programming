#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int N = 5e5 + 10;
constexpr ll inf = 1e18;
int a[N], b[N], p[N];
ll pre[N], suf[N], prea[N], preb[N], suma, sumb;

void solve() {
	int n; cin >> n;
	suma = sumb = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i], p[i] = i, suma += a[i], sumb += b[i];
	sort(p + 1, p + n + 1, [&](int x, int y){
		if ((a[x] <= b[x]) != (a[y] <= b[y])) return (a[x] <= b[x]) > (a[y] <= b[y]);
		if (a[x] <= b[x]) return a[x] < a[y];
		return b[x] > b[y];
	});
	prea[0] = preb[0] = 0LL;
	for (int i = 1; i <= n; i++)
		prea[i] = prea[i - 1] + a[p[i]], preb[i] = preb[i - 1] + b[p[i]];
	pre[0] = suf[n] = -inf;
	for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], prea[i] - preb[i - 1]);
	for (int i = n - 1; i; i--) suf[i] = max(suf[i + 1], prea[i + 1] - preb[i]);
	ll ans = inf;
	for (int i = 1; i <= n; i++)
		if (sumb - b[p[i]] >= suma)
			ans = min(ans, max({0LL, pre[i - 1], suf[i] - a[p[i]] + b[p[i]]}));
	if (ans == inf) ans = -1;
	else ans += suma;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}

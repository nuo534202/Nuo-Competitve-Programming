#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 10;
int n, q, a[N], pos[N] = { 0 }, maxL[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxL[i] = max(maxL[i - 1], pos[a[i]]), pos[a[i]] = i;
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (maxL[y] < x) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int n, m, pre[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		pre[l + r]++;
	}
	for (int i = 1; i < N; i++)
		pre[i] += pre[i - 1];
	while (m--) {
		int l, r;
		cin >> l >> r;
		cout << pre[r << 1] - pre[(l << 1) - 1] << "\n";
	}
	return 0;
}

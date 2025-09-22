#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> t(n), p(n);
	for (int i = 0; i < n; i++)	cin >> t[i];
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int x, int y){
		if (t[x] == t[y]) return x < y;
		return t[x] < t[y];
	});
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cout << p[i] + 1;
		if (i < n - 1) cout << ' ';
		else cout << endl;
		if  (i) ans += (long long)t[p[i - 1]] * (n - i);
	}
	cout << fixed << setprecision(2) << (double)ans / n << endl;
	return 0;
}

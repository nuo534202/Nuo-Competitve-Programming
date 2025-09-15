#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e4 + 5;
int n, m, a[N], b, vis[N];
bool not_prime[N << 1];
vector<int> prime;

void is_prime(int n) {
	memset(not_prime, false, sizeof(not_prime));
	not_prime[0] = not_prime[1] = true;
	for (int i = 2; i < n; i++) {
		if (!not_prime[i]) prime.push_back(i);
		for (int j = 0; j < (int)prime.size() && i * prime[j] < n; j++) {
			not_prime[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b, vis[b] = 1;
	is_prime(N << 1);
	int ans = 0;
	for (int i : prime) {
		if (i > n + m) break;
		for (int j = 1; j <= n; j++)
			if (i - a[j] >= 1 && i - a[j] <= 20000 && vis[i - a[j]]) {
				ans++;
				break;
			}
	}
	cout << ans << endl;
	return 0;
}

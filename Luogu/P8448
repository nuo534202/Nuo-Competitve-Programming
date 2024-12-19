#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 10;
bool not_prime[N];
vector<int> prime;

void is_prime(int n) {
	memset(not_prime, false, sizeof(not_prime));
	not_prime[1] = true;
	for (int i = 2; i <= n; i++) {
		if (not_prime[i] == false)  prime.push_back(i);
		for (int j = 1; j <= prime.size() && i * prime[j - 1] <= n; j++) {
			not_prime[prime[j - 1] * i] = true;
			if (i % prime[j - 1] == 0) break;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	is_prime(1000000);
	int T; cin >> T;
	while (T--) {
		int n, ans = 0; cin >> n;
		while (1) {
			bool flag = false;
			for (int i = 0; i < prime.size(); i++) {
				if (n % (prime[i] * prime[i] * prime[i]) == 0) {
					n = n / (prime[i] * prime[i] * prime[i]);
					flag = true, ans++;
					break;
				}
			}
			if (!flag) break;
		}
		cout << ans << '\n';
	}
	return 0;
}

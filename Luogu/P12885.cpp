#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long ans = 0;
	for (int i = 0; i < 2025; i++)
		for (int j = 0; j < 2025; j++)
			ans += 1LL * (2025 - i) * (2025 - j);
	cout << ans;
	return 0;
}

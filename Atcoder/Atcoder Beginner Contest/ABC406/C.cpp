#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e5 + 5;
int n, p[N], cnt[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	int num = 1;
    for (int i = 2; i <= n; i++) {
		if (p[i] > p[i - 1]) cnt[num]++;
		else if (cnt[num]) num++;
	}
	ll ans = 0;
	for (int i = 1; i <= num; i++) ans += 1LL * cnt[i - 1] * cnt[i];
	cout << ans << endl;
    return 0;
}

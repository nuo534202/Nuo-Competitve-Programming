#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10;
int n, a[N];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, ans = 0;
    map<int, int> cnt; // 记录数字在连续子串中是否出现
    for (int r = 1; r <= n; r++) {
		if ((r > 1 && a[r] == a[r - 1]) || (r - l) % 2 == 0) {
        	cnt[a[r]]++;
			while (cnt[a[r]] > 2) {
				cnt[a[l]]--;
				if (cnt[a[l]] == 0) cnt.erase(a[l]);
				l++;
			}
			if ((r - l + 1) % 2 == 0) {
				ans = max(ans, r - l + 1);
			}
		}
		else {
			cnt.clear();
			l = r;
			cnt[a[r]] = 1;
		}
    }
    cout << ans << endl;
    return 0;
}

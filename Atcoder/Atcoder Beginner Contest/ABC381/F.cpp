#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n + 1), dp(1 << 20 + 5, INT_MAX);
	vector<vector<int>> pos(21);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i); // 记录 a[i] 出现的位置
	}
	dp[0] = 0;
	int ans = 0;
	for (int j = 1; j < (1 << 20); j++) {
		for (int i = 1; i <= 20; i++) {
            	// j 为当前状态，需要判断 j 状态中 i 对应的位置上是否为 1
            	// 即 j 状态是否表示已经包含了 i 这个数字
            	// 同时还需要判断 j ^ (1 << (i - 1)) 这个状态是否存在
			if ((j & (1 << (i - 1))) && dp[j ^ (1 << (i - 1))] != INT_MAX) {
				int idx = upper_bound(pos[i].begin(), pos[i].end(), dp[j ^ (1 << (i - 1))]) - pos[i].begin();
                // 找出第一个在 dp[j ^ (1 << (i - 1))] 后面的 i 的位置
				if (idx + 1 < pos[i].size()) dp[j] = min(dp[j], pos[i][idx + 1]);
                // 子序列需要插入两个相同的数，所以判断 idx + 1 是否合法
			}
		}
		if (dp[j] != INT_MAX) {
			int res = 0, tmp = j;
			while (tmp) res += (tmp & 1), tmp >>= 1; // 统计 j 的二进制表示中 1 的个数
			ans = max(ans, 2 * res);
		}
	}
	cout << ans << '\n';
	return 0;
}

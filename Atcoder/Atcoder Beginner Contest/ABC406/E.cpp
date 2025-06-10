#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;
int n, k, c[65][65];

// 预处理组合数
void init() {
    c[0][0] = 1;
    for (int i = 1; i <= 60; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}

// cur 是当前位置，sum 是当前的和，cnt 是剩余要放置的 1 的数量
int dfs(int cur, int sum, int cnt) {	
	// 不合法条件：sum 大于 n，剩余位置无法放下需要放置的 1
    if (sum > n || cnt > cur + 1) return 0;
    
    // 所有 1 都放完了，sum 就是要加上的答案
    if (cnt == 0) return sum % mod;
    // 剩余的 cnt 个 1 可以放在 0 - p 任意一个位置
    if (sum + (1LL << (cur + 1)) - 1 <= n) {
        int oup = ((1LL << (cur + 1)) - 1) % mod * c[cur][cnt - 1] % mod;
        oup = (oup + c[cur + 1][cnt] * (sum % mod) % mod) % mod;
        return oup;
    }
    return (dfs(cur - 1, sum, cnt) + dfs(cur - 1, sum + (1LL << cur), cnt - 1)) % mod;
}

void solve() {
    cin >> n >> k;
    cout << dfs(59, 0, k) << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

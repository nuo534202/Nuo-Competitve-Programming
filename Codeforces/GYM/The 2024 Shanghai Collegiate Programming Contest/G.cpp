#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int mod = 998244353, dx[8] = { 1, -1, 2, 2, 1, -1, -2, -2 }, dy[8] = { 2, 2, 1, -1, -2, -2, 1, -1 };
const int jdx[4] = { 0, 1, 0, -1 }, jdy[4] = { 1, 0, -1, 0 }; // 判断别马脚
const int pw[11] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 }; // 2 的乘方
int n, m, vis[105][105], x[15], y[15], ok[105][105][1100], dp[105][105][1100];
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
signed main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) x[i] = read(), y[i] = read(), vis[x[i]][y[i]] = i; 
    // vis 数组记录 (i, j) 位置上的马的编号
	for (int k = 0; k < pw[m]; k++) {
		for (int i = 1; i <= m; i++) {
			if (k & pw[i - 1]) {
				for (int j = 0; j < 8; j++) {
					int xx = x[i] + dx[j], yy = y[i] + dy[j], num = vis[x[i] + jdx[j / 2]][y[i] + jdy[j / 2]];
					if (num && (k & pw[num - 1])) continue; // 别马脚
					if (xx < 0 || xx > n || yy < 0 || yy > n) continue;
					ok[xx][yy][k] = 1;
				}
			} // 当前状态下第 i 只马没有被吃掉
		}
	} // 预处理 ok 数组
	if (ok[0][0][pw[m] - 1]) dp[0][0][pw[m] - 1] = 0;
	else dp[0][0][pw[m] - 1] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 && j == 0) continue;
			for (int k = 0; k < pw[m]; k++) {
				if (!vis[i][j]) { // 当前位置没有马
					int num1 = 0, num2 = 0;
					if (i > 0) num1 = dp[i - 1][j][k];
					if (j > 0) num2 = dp[i][j - 1][k];
					if (!ok[i][j][k]) dp[i][j][k] = (num1 + num2) % mod;
					else dp[i][j][k] = 0;
				} else { // 当前位置有马
					if (k & pw[vis[i][j] - 1] == 0) continue; // k 状态表示当前的马已被吃掉
					int num1 = 0, num2 = 0;
					if (i > 0) num1 = dp[i - 1][j][k];
					if (j > 0) num2 = dp[i][j - 1][k];
					if (!ok[i][j][k ^ pw[vis[i][j] - 1]]) dp[i][j][k ^ pw[vis[i][j] - 1]] = (num1 + num2) % mod;
                    // 保证当前位置的马在 k 状态下是存活状态
					else dp[i][j][k ^ pw[vis[i][j] - 1]] = 0;
				}
			}
		}
	}
	int ans = 0LL;
	for (int k = 0; k < pw[m]; k++) if (!ok[n][n][k]) ans = (ans + dp[n][n][k]) % mod;
	printf("%lld", ans);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll pw[31] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
// 也可以利用循环进行预处理
const int N = 35;
int n, m, a[N], b[N], p[N], half;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
bool cmp(int x, int y) {
	if (b[x] == b[y]) return a[x] < a[y];
	return b[x] > b[y];
}
 
void dfs(vector<vector<pair<ll, ll>>> &v, int cur, ll sum, ll num, ll cost) {
	if (cur <= n - half) return;
	sum += num * b[p[cur]], cost += a[p[cur]];
	num++;
	v[num].push_back({cost, sum});
	dfs(v, cur - 1, sum, num, cost); // 选当前使命
	num--;
	cost -= a[p[cur]], sum -= num * b[p[cur]];
	dfs(v, cur - 1, sum, num, cost); // 不选当前使命
}
 
signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read(), p[i] = i;
	sort(p + 1, p + n + 1, cmp); // 按照 b 从大到小排序
	half = n / 2;
	vector<vector<pair<ll, ll>>> v(half + 1); // v[i] 是选择 i 个使命的时光集合
	vector<vector<ll>> pre_max(half + 1); // pre_max[i] 存的是 v[i] 前缀中的最大值
	dfs(v, n, 0LL, 0LL, 0LL); // 利用搜索预处理后半使命
	ll tmp;
	for (int i = 0; i <= half; i++) {
		sort(v[i].begin(), v[i].end());
		tmp = 0LL;
		pre_max[i].resize(v[i].size());
		for (int j = 0; j < v[i].size(); j++) {
			tmp = max(tmp, v[i][j].second);
			pre_max[i][j] = tmp;
		}
	}
	ll ans = 0LL, sum, cost, num, pre_sum;
    // sum 存获得的回忆，cost 存消耗的使
    //num 存选择使命的个数，pre_sum 存每一个使命的 b 的和
    // 枚举每一种情况
	for (int i = 0; i < pw[n - half]; i++) {
		sum = num = cost = pre_sum = 0LL;
		for (int j = n - half; j >= 1; j--) {
			if (i & pw[j - 1]) {
				sum += num * b[p[j]];
				cost += a[p[j]];
				pre_sum += b[p[j]];
				num++;
			}
			if (cost > m) break;
		}
		if (cost <= m) {
			tmp = 0LL;
			for (int i = 1; i <= half; i++) {
				int l = 0, r = v[i].size() - 1, pos = 0;
				while (l <= r) {
					int mid = l + r >> 1;
					if (v[i][mid].first < m - cost) l = mid + 1, pos = mid;
					else r = mid - 1;
				}
				if (v[i][pos].first <= m - cost)
                    tmp = max(tmp, i * pre_sum + pre_max[i][pos]);
                    // 前面选的使命在后面的若干轮也会继续获得回忆
			}
			ans = max(ans, sum + tmp);
		}
	}
	printf("%lld", ans);
    return 0;
}

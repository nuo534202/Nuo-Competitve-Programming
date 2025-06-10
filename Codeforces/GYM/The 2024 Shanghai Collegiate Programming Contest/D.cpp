#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)
 
const int N = 1e5 + 10, mod = 998244353, inf = 1e9;
int n, q, add[N], mul[N], pre[N], nxt[N];
struct tree { int mul, add; } t[N << 2];
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
void pushUp(int p) {
	t[p].mul = t[ls].mul * t[rs].mul % mod;
	t[p].add = (t[ls].add * t[rs].mul % mod + t[rs].add) % mod;
} // 乘法优先 (ax + b) * c + d = acx + bc + d
 
void build(int p = 1, int l = 1, int r = n) {
	if (l == r) {
		t[p].mul = mul[l];
		if (t[p].mul == 1) t[p].add = add[l];
		else t[p].add = 0; // mul > 1 则 不选择 add
		t[p].mul %= mod, t[p].add %= mod;
		return;
	}
	build(ls, l, mid), build(rs, mid + 1, r);
	pushUp(p);
}
 
pair<int, int> query(int ql, int qr, int p = 1, int l = 1, int r = n) {
	if (ql <= l && r <= qr) return { t[p].mul % mod, t[p].add % mod };
	pair<int, int> L = { 1, 0 }, R = { 1, 0 };
	if (ql <= mid) L = query(ql, qr, ls, l, mid);
	if (qr > mid) R = query(ql, qr, rs, mid + 1, r);
	int mul = L.first * R.first % mod, add = (L.second * R.first % mod + R.second) % mod;
	return { mul, add };
} // 第一个元素代表乘的数，第二个数代表加的数
 
signed main() {
	n = read();
	char s[20];
	for (int i = 1; i <= n + 1; i++) add[i] = pre[i] = 0, nxt[i] = n, mul[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			scanf("%s", s);
			int num = 0, len = strlen(s);
			for (int k = 1; k < len; k++) num = num * 10 + s[k] - '0';
			if (s[0] == '+') add[i] = max(add[i], num);
			else mul[i] = max(mul[i], num);
		}
		pre[i] = pre[i - 1] + add[i]; // 记录 add 的前缀和
	}
	for (int i = n; i; i--) nxt[i] = mul[i] > 1 ? i : nxt[i + 1]; // 存下一个 mul > 1 的位置
	build();
	q = read();
	while (q--) {
		int u = read(), l = read(), r = read();
		r++;
		while (l < r && u <= inf) {
			int i = min(nxt[l], r);
			u += pre[i - 1] - pre[l - 1]; // [i, l - 1] 区间，mul = 1，都选择加
			l = i;
			if (l == r || u > inf) break;
			u = max(u * mul[l], u + add[l]); // 判断选择加还是乘
			l++;
		}
		u %= mod;
		pair<int, int> ans = { 1, 0 };
		if (l < r) ans = query(l, r - 1);
		int oup = u * ans.first % mod + ans.second;
		printf("%lld\n", oup % mod);
	}
	return 0;
}

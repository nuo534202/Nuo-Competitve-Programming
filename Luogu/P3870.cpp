#include <bits/stdc++.h>
using namespace std;
 
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
 
const int N = 1e5 + 10;
int n, m;
struct tree { int num, tag = 0; } t[N << 2];
// num 存区间内开着的灯的数量
// tag 存是否需要进行开关灯操作，0 表示不需要，1 表示需要
// 利用异或 (^) 来改变 tag 的值
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
void pushUp(int p) { t[p].num = t[ls].num + t[rs].num; }
 
void pushDown(int p, int l, int r) {
	if (t[p].tag) {
		t[ls].num = mid - l + 1 - t[ls].num, t[rs].num = r - mid - t[rs].num;
        	// 区间长度减去关着的灯的数量即为开着的灯的数量
		t[ls].tag ^= 1, t[rs].tag ^= 1, t[p].tag ^= 1;
	}
}
 
void modify(int ql, int qr, int p = 1, int l = 1, int r = n) {
	if (ql <= l && r <= qr) {
		t[p].num = r - l + 1 - t[p].num, t[p].tag ^= 1;
		return;
	}
	pushDown(p, l, r);
	if (ql <= mid) modify(ql, qr, ls, l, mid);
	if (qr > mid) modify(ql, qr, rs, mid + 1, r);
	pushUp(p);
}
 
int query(int ql, int qr, int p = 1, int l = 1, int r = n) {
	if (ql <= l && r <= qr) return t[p].num;
	pushDown(p, l, r);
    	int ans = 0;
	if (ql <= mid) ans += query(ql, qr, ls, l, mid);
	if (qr > mid) ans += query(ql, qr, rs, mid + 1, r);
	return ans;
}
 
int main() {
	n = read(), m = read();
	while (m--) {
		int c = read(), a = read(), b = read();
		if (c == 0) modify(a, b);
		if (c == 1) printf("%d\n", query(a, b));
	}
	return 0;
}

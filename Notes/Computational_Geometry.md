# Computational Geometry

All the solutions of the practice problems in this markdown file is in [Computational Geometry Solutions](./solution/Computational_Geometry.md).

## Convex Hull

### Practice Problems

- [Luogu P3194](https://www.luogu.com.cn/problem/P3194) - Blue

# 平面最近点对

## 分治法

题目链接：[HDU 1007](https://acm.hdu.edu.cn/showproblem.php?pid=1007)

使用 `<algorithm>` 头文件中的 `std::inplace_merge()` 来执行归并排序，它的作用是将一个序列中**两个连续且已经有序**（通常为升序）的子序列，原地（in-place） 合并成一个更大的有序序列。如果是两个降序序列要自定义比较函数，例如 `std::inplace_merge(v.begin(), v.begin() + 4, v.end(), std::greater<int>());`。

时间复杂度： $O(n\log n)$。

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, ansa, ansb;
double mindis;
struct pt { double x, y; int id; } p[N], t[N];

void update_ans(const pt& a, const pt& b) {
	double dis = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	if (mindis > dis) mindis = dis, ansa = a.id, ansb = b.id;
}

bool cmpx(const pt& a, const pt& b) {
	return a.x < b.x;
}

bool cmpy(const pt& a, const pt& b) {
	return a.y < b.y;
}

void rec(int l, int r) {
	if (r - l <= 3) {
		for (int i = l; i <= r; i++)
			for (int j = i + 1; j <= r; j++) update_ans(p[i], p[j]);
		sort(p + l, p + r + 1, cmpy);
		return;
	}

	int mid = (l + r) >> 1, midx = p[mid].x;
	rec(l, mid), rec(mid + 1, r);
	inplace_merge(p + l, p + mid + 1, p + r + 1, cmpy);

	int cnt = 0;
	for (int i = l; i <= r; i++)
		if (abs(p[i].x - midx) < mindis) {
			for (int j = cnt; j && p[i].y - t[j].y < mindis; j--)
				update_ans(p[i], t[j]);
			t[++cnt] = p[i];
		}
}

void solve() {
	for (int i = 1; i <= n; i++)
		cin >> p[i].x >> p[i].y, p[i].id = i;
	mindis = 1e9, ansa = ansb = 0;
	sort(p + 1, p + n + 1, cmpx);
	rec(1, n);
	cout << fixed << setprecision(2) << mindis / 2 << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		cin >> n;
		if (!n) break;
		solve();
	}
	return 0;
}
```

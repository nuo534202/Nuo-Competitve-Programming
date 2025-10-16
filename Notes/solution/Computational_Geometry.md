# Computational Geometry Solutions

## Convel Hull

### Luogu P3194 - Blue

**题目链接**：[Luogu P3194](https://www.luogu.com.cn/problem/P3194)

**题目描述**：在 $x-y$ 直角坐标平面上有 $n$ 条直线 $L_1,L_2,…L_n$，若在 $y$ 值为正无穷大处往下看，能见到 $L_i$ 的某个子线段，则称 $L_i$ 为可见的，否则 $L_i$ 为被覆盖的。

例如，对于直线: $L_1:y=x$, $L_2:y=-x$, $L_3:y=0$, 则 $L_1$ 和 $L_2$ 是可见的，$L_3$ 是被覆盖的。给出 $n$ 条直线，表示成 $y=Ax+B$ 的形式($|A|,|B| \le 500000$)，且 $n$ 条直线两两不重合，求出所有可见的直线。

**题解**

可以发现如果所有可见的直线围起来会形成一个凸包，只需要以 $A$ 为第一关键字从小到大排序， $B$ 为第二关键字从大到小排序，再用栈维护凸包即可。

判断当前直线是否会遮住前面的直线使其不可见，只需要判断当前直线与 `st[top]` 对应直线交点的横坐标是否在，`st[top]` 跟 `st[top - 1]` 对应直线交点的横坐标右侧即可。

**代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

#define eps 1e-8

const int N = 5e4 + 5;
int n, a[N], b[N], p[N], st[N], top = 0;

double ints(int x, int y) {
    return (double)(b[x] - b[y]) / (double)(a[y] - a[x]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i], p[i] = i;
    sort(p + 1, p + n + 1, [&](int x, int y){
        if (a[x] == a[y]) return b[x] > b[y];
        return a[x] < a[y];
    });
    st[++top] = p[1];
    for (int i = 2; i <= n; i++) {
        if (a[p[i]] != a[p[i - 1]]) {
            while (top >= 2 && ints(st[top - 1], st[top]) >= ints(st[top], p[i]))
                top--;
            st[++top] = p[i];
        }
    }
    sort(st + 1, st + top + 1);
    for (int i = 1; i <= top; i++) {
        cout << st[i];
        if (i < top) cout << " ";
        else cout << endl;
    }
    return 0;
}
```
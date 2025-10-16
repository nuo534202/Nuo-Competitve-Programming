# Data Structure Solutions

## Stack & Monotonic Stack

### Luogu P3551 - Green

**题目链接**：[Luogu P3551](https://www.luogu.com.cn/problem/P3551)

**题目描述**：有 $n$ 块砖，其中白色是黑色的 $k$ 倍，求一个消除序列，满足以下条件：每次消除 $k + 1$ 个砖，其中 $k$ 块白色， $1$ 块黑色，并且这 $k + 1$ 块砖从开始到结束，中间不能路过已经消除过的砖。

**题解**：由于每一次消除中间不能路过已经消除过的砖，那么在去除之前消除过的砖的前提下，每一次选取的砖都是连续的。我们可以手写一个栈进行维护，如果栈末尾的 $k + 1$ 个元素恰好有一块黑色的砖，那么我们直接选取这 $k + 1$ 块砖作为本次选取的答案，不断重复这个操作直到结束为止。为了保证输出的答案满足升序，因此输出的时候要反向输出，具体实现看代码。

时间复杂度： $O(n)$。

**代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, k, st[N], ans[N], pre[N], top = 0, cnt = 0;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        st[++top] = i;
        pre[top] = pre[top - 1] + (s[i] == 'c');
        if (top >= k + 1 && pre[top] - pre[top - k - 1] == 1) {
            for (int i = top; i >= top - k; i--)
                ans[++cnt] = st[i] + 1;
            top -= (k + 1);
        }
        if (top == 0) {
            for (int i = cnt; i; i--) {
                cout << ans[i];
                if (i % (k + 1) == 1) cout << endl;
                else cout << " ";
            }
            cnt = 0;
        }
    }
    for (int i = cnt; i; i--) {
        cout << ans[i];
        if (i % (k + 1) == 1) cout << endl;
        else cout << " ";
    }
    return 0;
}
```

### Luogu P4147 - Green

**题目链接**：[Luogu P4147](https://www.luogu.com.cn/problem/P4147)

**题目描述**：给出 $N \times M$ 个格子，每个格子里面写着 `R` 或者 `F`，输出全是 `F` 的最大矩形面积 $\times 3$ 的结果。

**题解**

直接枚举二维矩形的两个对角顶点再去进行检查的暴力做法复杂度非常高，无法在时间范围内通过本题，因此要考虑对时间做优化。

对于一个 $r \times c$ 的矩形，我们可以把它看成有个有 $r$ 个 $1 \times c$ 的小矩形组合而来的大矩形。也就是说，对于左上角坐标为 $(i_1, j_1)$，右下角坐标为 $(i_2, j_2)$ 的矩形来说，如果它的长是 $i_2 - i_1$，它的宽就是 $[i_1, i_2]$ 里面每一行以 $j_2$ 结尾的最小的连续的 `R` 的数量。

因此，我们维护一个 $pre_{i, j}$ 表示以第 $i$ 行第 $j$ 列结尾的连续 `R` 的数量。接着，我们再去按列枚举，对于每一列我们用单调栈处理出每一行上面和下面第一个连续 `R` 数量小于当前行的位置，然后我们枚举每一行作为矩形的宽（连续 `R` 数量最小的一行），接着得出矩形的长，就可以找出右下角在这一列的最大矩形。

时间复杂度： $O(N \times M)$。

**代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, row[N][N], up[N], down[N];
char c[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 'R') row[i][j] = 0;
            else row[i][j] = row[i][j - 1] + 1;
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && row[st.top()][j] >= row[i][j]) {
                down[st.top()] = i;
                st.pop();
            }
            up[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            down[st.top()] = n + 1;
            st.pop();
        }
        for (int i = 1; i <= n; i++)
            ans = max(ans, (down[i] - up[i] - 1) * row[i][j]);
    }
    cout << ans * 3 << endl;
    return 0;
}
```

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
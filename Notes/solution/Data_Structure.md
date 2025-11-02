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

## Queue & Monotonic Queue

### Luogu P2564 - Green

**题目链接**：[Luogu P2564](https://www.luogu.com.cn/problem/P2564)

**题目描述**：在包含 $N$ 个 $K$ 种彩珠的 $x$ 轴上，找一段能覆盖所有 $K$ 种彩珠的最短区间，求该区间的长度。

**题解**

个人认为只有黄题的难度

将 $(pos, tag)$ 组成一个 $pair$，其中 $pos$ 代表彩珠位置，$tag$ 代表彩珠种类，对这个 $pair$ 进行排序。用 $queue$ 找出最短区间长度，具体实现看代码。

时间复杂度： $O(n\log n)$。

**代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector<pair<int, int>> v;
    vector<int> vis(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            int pos;
            cin >> pos;
            v.push_back({ pos, i });
        }
    }
    sort(v.begin(), v.end());
    queue<int> q;
    int ans = INT_MAX;
    bool flag = false;
    for (int i = 0; i < (int)v.size(); i++) {
        q.push(i);
        vis[v[q.back()].second]++;
        if (!flag && vis[v[q.back()].second] == 1) {
            bool cur = true;
            for (int j = 1; j <= k; j++)
                if (!vis[j]) {
                    cur = false;
                    break;
                }
            flag = cur;
        }
        if (flag)
            while (q.size() > k && vis[v[q.front()].second] > 1)
                vis[v[q.front()].second]--, q.pop();
        if (flag)
            ans = min(ans, v[q.back()].first - v[q.front()].first);
    }
    cout << ans << endl;
    return 0;
}
```

### Luogu P9588 - Green

**题目链接**：[Luogu P9588](https://www.luogu.com.cn/problem/P9588)

**题目描述**

第一行输入 $c$, $q$ 两个整数，分别表示测试点编号和操作次数。

- `1 x`：在队尾插入 $1$, $2$, $\cdots$, $x$。
- `2 y`：弹出对头的 $y$ 个元素。
- `3 z`：查询队列中的第 $z$ 个元素。
- `4`：查询队列中所有元素的最大值。

**题解**

观察到题目的数据量，所有插入、删除、查询操作肯定没法直接模拟。

- 操作一：由于操作一插入的数据范围是 $[1, x]$，所以只需要记录下 $x$ 即可，也就是向队尾插入一个 $x$。
- 操作二：由于操作一的插入只记录了最后一个元素 $x$，所以没法直接在队列中实现删除操作，但可以用一个变量 $del$ 记录下队头被删除的元素数量。
- 操作三：由于删除操作方式，这里要找的实际上是从头开始的第 $del + x$ 位置。对于队列记录一个前缀和 $pre$，这个前缀和表示队列实际的元素数量，在利用二分在 $pre$ 数组上找到要查询的元素位于哪一个位置的 $[1, x]$ 上。
- 操作四：用一个 `multiset` 记录所有 $x$，在操作二的操作中，从 `multiset` 中移除被删除的 $x$。

时间复杂度： $O(n\log n)$。

**代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int q, c, del = 0, cur = 1, val[N], pre[N], cnt = 0;

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> q;
    multiset<int> s;
    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            cnt++;
            val[cnt] = x, pre[cnt] = pre[cnt - 1] + x;
            s.insert(x);
        }
        if (op == 2) {
            cin >> x;
            del += x;
            while (cur <= cnt && pre[cur] <= del)
                s.erase(s.find(val[cur++]));
        }
        if (op == 3) {
            cin >> x;
            int pos = lower_bound(pre + 1, pre + cnt + 1, x + del) - pre;
            cout << x + del - pre[pos - 1] << '\n';
        }
        if (op == 4) {
            cout << *s.rbegin() << '\n';
        }
    }
    return 0;
}
```

### Luogu P2219 - Blue

**题目链接**：[Luogu P2219](https://www.luogu.com.cn/problem/P2219)

**题目描述**：给出一个 $M \times N$ 的矩形，矩形的每一个位置都有一个值，在一个 $A \times B$ 的大矩形内去除一个 $C \times D$ 的小矩形，两个矩形的边不能重合，求出去除小矩形后原大矩形内剩余元素的最大和。

**题解**

假设大矩形的右下角坐标为 $(x_1, y_1)$，小矩形的右下角坐标为 $(x_2, y_2)$，那么一定满足 $x1 - (a - c) + 1 < x_2 < x_1$ 和 $y_1 - (b - d) + 1 < y_2 < y_1$。我们可以先维护两个二维前缀和 $ab_{i, j}$ 和 $cd_{i, j}$ 分别表示以 $(i, j)$ 为右下角的变长分别为 $A \times B$ 和 $C \times D$ 的和。

如果已知大矩形的右下角坐标 $(i, j)$，那么我们只需要知道以 $(i - (a - c) + 2, j - (b - d) + 2)$ 和 $(i - 1, j - 1)$ 为左上角和右下角的矩形内最小的 cd 值即可得到当前大矩形位置的最大元素和，这里在横纵两个方向分别用单调队列进行处理即可。

时间复杂度： $O(MN)$。

**代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int m, n, a, b, c, d, pre[N][N], ab[N][N], cd[N][N];
int rowMin[N][N], colMin[N][N];
int dq[N], front = 1, back = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n >> a >> b >> c >> d;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> pre[i][j];
            pre[i][j] = pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (i >= a && j >= b)
                ab[i][j] = pre[i][j] - pre[i - a][j] - pre[i][j - b] + pre[i - a][j - b];
            if (i > c && i < m && j > d && j < n)
                cd[i][j] = pre[i][j] - pre[i - c][j] - pre[i][j - d] + pre[i - c][j - d];
        }
    }
    for (int i = c + 1; i < m; i++) {
        front = 1, back = 0;
        for (int j = d + 1; j < n; j++) {
            while (front <= back && cd[i][dq[back]] > cd[i][j])
                back--;
            dq[++back] = j;
            while (front <= back && j - dq[front] > b - d - 2)
                front++;
            if (j >= b - 1)
                rowMin[i][j + 1] = cd[i][dq[front]];
        }
    }
    for (int j = b; j <= n; j++) {
        front = 1, back = 0;
        for (int i = c + 1; i < m; i++) {
            while (front <= back && rowMin[dq[back]][j] > rowMin[i][j])
                back--;
            dq[++back] = i;
            while (front <= back && i - dq[front] > a - c - 2)
                front++;
            if (i >= a - 1)
                colMin[i + 1][j] = rowMin[dq[front]][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= a && j >= b) {
                ans = max(ans, ab[i][j] - colMin[i][j]);
            }
        }
    }
    cout << ans << endl
    return 0;
}
```

## Disjoint Sets

### Luogu P8654 - Yellow

**题目链接**：[Luogo P8654](https://www.luogu.com.cn/problem/P8654)

**题目描述**：一个种植园被分成 $m \times n$ 个小格子，每个格子里种了一株合根植物。这种植物的根可能会沿着南北或东西方向伸展，从而与另一个格子的植物合成为一体。给出哪些小格子间出现了连根现象，找出这个园中一共有多少株合根植物。

**题解**：用并查集将连根的植物合并在一起，最后并查集的集合数量就是答案。

时间复杂度： $O(\max(k, m \times n))$。

**代码**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, k, f[N], vis[N], ans = 0;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n * m; i++)
        f[i] = i;
    while (k--) {
        int a, b;
        cin >> a >> b;
        f[find(a)] = find(b);
    }
    for (int i = 1; i <= n * m; i++) {
        int x = find(i);
        if (!vis[x]) {
            vis[x] = 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
```
# My solution

比赛链接：[Atcoder Beginner Contest 395](https://atcoder.jp/contests/abc395)

博客链接：[ABC395](https://www.cnblogs.com/nuo534202/articles/18947577)

## A - Strictly Increasing?
按照题意模拟

## B - Make Target
按照题意模拟

## C - Shortest Duplicate Subarray
对于每一个相同的 $a$ 的值，记录他们的下标，答案是相距最近的两个相同的 $a$ 值的距离

时间复杂度： $O(N + A)$（ $A$ 代表 $A_i$ 的最大值）。

## D - Pigeon Swap
- 对于第一种操作，只需要对每一个鸽子记录一个 $f_i$，表示第 $i$ 只鸽子所在的鸟巢编号。
- 对于第二种操作，
	- 要将所有 $f_i = a$ 的位置，变成 $f_i = b$。
	- 同时将所有 $f_i = b$ 的位置，变成 $f_i = a$。
如果暴力的做，那么时间复杂度是 $O(n)$，无法满足题目限制。
- 可以发现 $f_i$ 的值跟最终的鸟巢编号存在一个映射的关系，所以记录一个 $pos_i$ 来表示这个映射关系。初始化 $pos_i = i$，表示最开始每一个 $f_i$ 的值都表示对应的鸟巢。对于第二种操作，只需要更改对应的映射关系即可，即交换 $pos_a$ 跟 $pos_b$ 的值。
- 但此事第一个操作就不能直接赋值 $f_i = b$ 了，而是要让 $f_i = j$（ $pos_j = b$），所以要另外再记一个 $idx_i$ 作为跟 $pos_i$ 刚好相反的一个映射，方便进行操作一。

在这样的情况下，

- 操作一实际上就是让 $f_a = idx_b$。
- 操作二实际上是要分别交换 （ $pos_{idx_a}$, $pos_{idx_b}$），跟（ $pos_a$, $pos_b$）。
- 操作三实际上是要输出 $pos_{f_a}$。

时间复杂度： $O(N + Q)$。

## E - Flip Edge
对于每一对给出的 $(u, v)$，直接连一条有向边，权值为 $1$。

为了表示翻转操作，可以给 $(v + n, u + n)$ 连一条边，权值为 $1$，并且对于 $1 \le i \le n$，连 $(i, i + n)$ 跟 $(i + n, i)$ 两条边，权值都设为 $x$。

接着，直接从 $1$ 号节点开始跑 $dijsktra$，最后的答案为 $\min(dis_n, dis_{2n})$。

时间复杂度： $O(n\log n)$

## F - Smooth Occlusion
可以发现 $H$ 满足单调性（$H$ 越大花费越少），我们可以二分 $H$，然后 $O(n)$ 检查是不是符合条件。

检查实现：

- 对于每一个位置 $i$，需要进行的消除次数是 $U_i + D_i - H$。
- 为了满足 $|U_i - U_{i + 1}| \le X$ 的条件， $U_{i + 1}$ 可行的范围是 $[\min U_i - X, \max U_i + X]$。
- $\min U_i = \max(0, U_i - (U_i + D_i - H)) = \max (0, H - D_i)$ ， $\max U_i = U_i$。

时间复杂度： $O(N \log(U_i + D_i))$。

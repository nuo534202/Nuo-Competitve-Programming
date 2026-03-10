# Atcoder Beginner Contest 448

比赛链接：[Atcoder Beginner Contest 448](https://atcoder.jp/contests/abc448)

## A. chmin

按照题意模拟即可。

时间复杂度： $O(N)$。

## B. Pepper Addiction

尽量将每一个位置都填充到上限 $B$，填充完统计最后结果。

时间复杂度： $O(N)$。

## C. Except and Min

用 `multiset` 维护当前的数列，每一次查询将要删除的数从 `multiset` 中删除，输出当前 `multiset` 中的最小值，再将被删除的数重新插入 `multiset` 中。

时间复杂度： $O(N\log N + \sum K \log N)$

## D. Integer-duplicated Path

从节点 $1$ 开始进行 DFS，利用 `unordered_map` 记录路径上所有节点的值的出现个数，根据前面路径节点值出现的个数判断当前节点的值是否有出现过。

时间复杂度： $O(N)$。

## E. Simple Division

假设 $\left \lfloor \frac{N}{M} \right \rfloor = res$ ($mod\ 10007$)，那么可以得到 $N = 10007 \times M \times T + M \times res + b$，其中 $T$ 是一个非负整数，$b$ 是 $0$ 到 $M-1$ 之间的整数。从而得到 $\left \lfloor \frac{N}{M} \right \rfloor = \left\lfloor \frac{N \% (10007M)}{M} \right\rfloor$。

根据题目中的规则，可以发现 $N = N \times 10^l + \frac{10^l - 1}{9} \times c$，但由于模数 $10007M$ 不是质数，所以对于 $\frac{10^l - 1}{9}$ 无法利用费马小定理求乘法逆元。

但原式可以变形为 $9N = 9N \times 10^l + \frac{10^l - 1}{9} \times c$，我们可以先计算 $9N$，这个时候的模数就变成了 $10007M \times 9$。最后要输出的结果是 $\left\lfloor \frac{N \% (10007M \times 9)}{M} \right\rfloor$。

时间复杂度： $O(K\log l)$。

## F. Authentic Traveling Salesman Problem

平面范围为 $X\le 2\times10^7$，点数为 $N\le6\times10^4$。如果按普通的 (x) 再按 (y) 排序，可能会产生大量上下往返，使路径很长。一个常见技巧是 **蛇形扫描（Snake Order）**。

我们将平面按 $x$ 坐标分成若干宽度为 $B$ 的竖条，再进行排序。

排序规则：

1. 先按每一个块从小到大排序
2. 若在同一块：
    - **偶数块**：按 (y) 升序
    - **奇数块**：按 (y) 降序

这样访问顺序类似：

```
↑   ↓   ↑   ↓
|   |   |   |
|   |   |   |
```

路径在相邻块之间会自然连接，减少来回移动。

**块大小选择**

设块宽为 $B$，总路径长度可以估计为： $\frac{W^2}{B} + NB + O(W)$

当 $B = \frac{W}{\sqrt N}$ 时，总路径长度最小。

本题中 $X \le 2e7$, $N ≤ 6e4$，因此 $B \approx 8e4$，可以满足距离限制。

题目要求从 $1$ 开始出发，因此排序后找到 $1$ 的位置，再从该位置循环输出即可。

时间复杂度： $O(N \log N)$

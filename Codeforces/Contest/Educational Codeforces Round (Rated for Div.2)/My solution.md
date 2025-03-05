# Educational Codeforces Round (Rated for Div.2)

比赛链接：[Edu175](https://codeforces.com/contest/2070)

## A. FizzBuzz Remixed

因为 $i \% 3 = i \% 5$，所以 $i = 15k$， $i = 15k + 1$，或者 $i = 15k + 2$ ($k \in N$)。

时间复杂度： $O(1)$。

## B. Robot Program

$R$ 是右移，位置坐标 $+1$； $L$ 是左移，位置坐标 $-1$。维护一个前缀和，首先找到一个 $pre_i + x = 0$，的位置记录花费的时间，再找到第一个 $pre_i = 0$ 的位置，计算剩余时间能走回多少次原点。如果找不到 $pre_i + x = 0$ 的位置，或者需要花费的时间 $i$ 大于 $k$，那么输出 $-1$。

时间复杂度： $O(n)$。

## C. Limited Repainting

可以发现 $penalty$ 满足单调性，所以可以二分 $penalty$，再去这个 $penalty$ 检查是不是合法的。

检查的实现：

- 如果 $s_i = B$ 且 $a_i > mid$，那么这个位置一定要画成蓝色。
- 如果 $s_i = R$ 且 $a_i > mid$，那么这个位置一定不能画成蓝色。

时间复杂度： $O(n\log A)$ ($A$ 代表 $a_i$ 的最大值)。

## D. Tree Jumps

设 $dp_i$ 是以 $i$ 节点结尾的路径数量，记 $tot_i$ 表示上一层所有节点的方案数， $u_i$ 是 $i$ 节点的父节点，转移方程为 $dp_i = tot_i - dp_{u_i}$。最后的结果为 $\sum_{i = 1}^n dp_i$。

时间复杂度： $O(n)$。

## E. Game with Binary String

对于第二个玩家，最优的操作是在剩余字符串还有 $0$ 的时候，选 $01$，否则选 $11$。所以当两个玩家刚好能一人选一次到游戏结束时，子串中一定满足 $num_0 = 3 \cdot num_1$。

- 当 $num_0 \ge 3 \cdot num_1 + 2$ 时，玩家一能在两人一人选一次后多选一次，玩家一获胜。
- 当 $num_0 < 3 \cdot num_1 + 2$ 时，
	- 当 $num_0 = 3 \cdot num_1 - 1$ 时，在倒数第二轮选完之后，刚好只剩下两个 $0$、一个 $1$。玩家一获胜。
	- 剩余其他情况下，带倒数第二轮选完之后会剩下两个 $0$ 和若干个 $1$，玩家二获胜。

玩家一获胜的数量就是所有满足的 $num_0 - 3 \cdot num_1 \ge 2$ 或 $num_0 - 3 \cdot num_1 = -1$ 的子串数量。

设 $sum_i$ 表示前 $i$ 位的 $num_0 - 3 \cdot num_1$，所有以第 $i$ 位结尾的子串中，玩家一获胜的数量为满足 $1 \le j < i$ 且 $sum_j \le sum_i - 2$ 或 $sum_j = sum_i + 1$ 的 $j$ 的数量（满足 $sum_i - sum_j \ge 2$ 或 $sum_i - sum_j = -1$，其中 $sum_i - sum_j$ 表示的是 $(j, i]$ 的子串中的 $num_0 - 3 \cdot num_1$）。最后利用树状数组维护前 $i$ 位的 $sum$ 的数量和即可。

时间复杂度： $O(n \log n)$。

# My solution

## A - XOR Matching 2

题目链接：[ARC124B](https://atcoder.jp/contests/arc124/tasks/arc124_b?lang=en)

先利用 $x_i = a_0 \oplus b_i$ 所有可能的最终答案，接着再用 $c_i = a_i \oplus x_j$ 构造出 $c$ 数组，将 $b$， $c$ 数组分别排序后判断是否相同即可。

时间复杂度： $O(n\log n)$。

## B - Insurance

题目链接：[ARC122B](https://atcoder.jp/contests/arc122/tasks/arc122_b?lang=en)

- 要求的期望是 $\frac{\sum_{i = 1}^n (x + A_i - \min(A_i, 2x)}{n} = \frac{\sum_{i = 1}^n A_i}{n} + \frac{\sum_{i = 1}^n (x - \min(A_i, 2x))}{n}$，我们要最小化得就是 $y = nx - \sum_{i = 1}^n\min(A_i, 2x)) = (n - 2k)x + \sum_{i = k}^nA_i$ (假设在 $A$ 数组排序后 $[1, k - 1]$ 位置上的 $A$ 都小于等于 $2x$， $[k, n]$ 位置上的 $A$ 都大于等于 $2x$)。
- 对于 $A_{k - 1} < 2x < A_k$ 的情况
  - 如果 $n - 2k < 0$，令 $2x = A_k$ 不会改变 $k$，会让 $y$ 变得更小。
  - 如果 $n - 2k > 0$，令 $2x = A_{k - 1} 不会改变 $k$，会让 $y$ 变得更小。
  - 所以最优的 $x$ 一定满足 $2x = A_{1\le i \le n}$。
- 完整做法是先对数组排序，然后对 $A$ 数组处理出前缀和，找出最大的 $\frac{\sum_{i = 1}^n (x + A_i - \min(A_i, 2x)}{n}$ 即可。

时间复杂度： $O(n\log n)$。

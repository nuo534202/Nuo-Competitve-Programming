# My solution

比赛链接：[Codeforces Round 1063 (Div. 2)](https://codeforces.com/contest/2163)

## A. Souvlaki VS. Kalamaki

由于双方都会选择对自己最优的操作，那么如果 Souvlaki 想要赢，那么重排序后的序列无论 Kalamaki 选取哪一种操作都不能对结果造成影响。

最优的重排序的序列一定是从大到小排序，如果要 Kalamaki 不对结果造成影响，那么对于 $1 \le i < n$ 并且 $i$ 为偶数，必须满足 $a_i = a_{i + 1}$。

时间复杂度： $O(n\log n)$。
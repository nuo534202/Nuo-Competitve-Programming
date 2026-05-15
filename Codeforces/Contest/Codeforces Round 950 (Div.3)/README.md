# Codeforces Round 950 (Div.3)

比赛链接：[Codeforces Round 950 (Div.3)](https://codeforces.com/contest/1980)

## A. Problem Generator

读入的时候统计各种难度的数量，数量少于 $m$ 的，统计少了多少。

时间复杂度： $O(n)$ 。

## B. Choosing Cubes

分别记下大于第 $f$ 位和等于第 $f$ 位的数的数量，根据数量关系判断（具体看代码）。

时间复杂度： $O(n)$ 。

## C. Sofia and the Lost Operations

分别判断 $d[m]$ 是否出现在 $b$ 数组里面以及 $b$ 数组与 $a$ 数组不同的值是否能在 $d$ 数组里面找到。

时间复杂度： $O(n \log n)$ 。

## D. GCD-sequence

从 $b$ 数组递减的位置，分别删去对应的 $a$ 数组的元素，再生成新的 GCD 序列，判断新序列是否不递减。

时间复杂度： $O(n)$ 。
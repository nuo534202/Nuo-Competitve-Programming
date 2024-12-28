# My solution
Contest Link: https://atcoder.jp/contests/abc385

## A - Equally
只有三个数相等或者两个小的数加起来等于最大的数时输出 $Yes$，其他时候输出 $No$。

时间复杂度： $O(1)$。

## B - Santa Claus 1
按照题意模拟，用 $vis$ 数组记录经过的格子，最后统计这些格子中房子 ($@$) 的个数。

时间复杂度： $O(HW + |T|)$ ($|T|$ 代表字符串 $T$ 的长度)。

## C - Illuminate Buildings
设 $dp_{i, j}$ 表示考虑到第 $i$ 位，间隔为 $j$ 能装饰的建筑物数量。当 $h_i = h_{i - j}$ 时，状态转移方程为 $dp_{i, j} = max(dp_{i, j}, dp_{i - j, j} + 1)$。

时间复杂度： $O(N^2)$。

## D - Santa Claus 2
按照题意模拟过程。

找房子的方法：
- 用两个 $vector$ $vx$ 和 $vy$ 分别存房子的坐标 $(x, y)$ 和对应的 $(y, x)$ 并进行排序。
- 在上下移动的时候，利用二分在 $vx$ 中找出经过的点存入 $set$ 里面。
- 在左右移动的时候，利用二分在 $vy$ 中找出经过的点存入 $set$ 里面。

时间复杂度： $O(Mlog^2N)$。

## E - Snowflake Tree
可以发现在中心点和 $x$ 确定之后，整棵雪花树就可以确定下来了
枚举中心点，将中心点相邻的点按照度数从大到小进行排序。（未完待续）

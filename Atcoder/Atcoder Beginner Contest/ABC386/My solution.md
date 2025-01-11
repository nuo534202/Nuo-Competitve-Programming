# My solution

Contest Link: [Atcoder Beginner Contest](https://atcoder.jp/contests/abc386)

My Blog Link: [ABC386](https://blog.csdn.net/djhws144/article/details/145075561?sharetype=blogdetail&sharerId=145075561&sharerefer=PC&sharesource=djhws144&spm=1011.2480.3001.8118)

## A - Full House 2
如果四张卡片有三张相同的或者两两相同，并且四张不完全相同，输出 $Yes$，否则输出 $No$。

时间复杂度： $O(1)$。

## B - Calculator
根据题意模拟，具体实现看代码。

时间复杂度： $O(N)$。

## C - Operate 1
双指针从字符串两端开始进行匹配，只允许有一个失配的地方，最后两个指针应该都指向失配的那个位置。

时间复杂度： $O(N)$。

## D - Diagonal Separation
对于所有给出的 $(x_i, y_i, c_i)$，以 $x_i$ 为第一关键字，$c_i$ 为第二关键字进行排序。对于相同的 $x$，$c_i = B$ 的 $y$ 值要小于所有的 $c_i = W$ 的 $y$ 值。对于不同的 $x$，$x$ 较大的那一行 $c_i = B$ 对应的最大的 $y$ 值要小于上一行 $c_i = W$ 最小的 $y$ 值。

时间复杂度： $O(M\log M)$

## E - Maximize XOR
由于 $C_n^k \le 10^6$，实际上的 $min(k, n - k) \le 10$，因此可以直接搜索出每一种答案。对于 $k > \lceil \frac{n}{2} \rceil$，可以令 $k = n - k$，然后答案为搜索出来的答案 $XOR$ $A_1 \oplus A_2 \oplus \cdots \oplus A_n$。

时间复杂度： $O(2^{min(K, N - K)})$。

## F - Operate K
首先，可以设 $dp_{i, j}$ 为考虑到字符串 $s$ 的第 $i$ 位，字符串 $t$ 的第 $j$ 位时，需要进行的操作次数，但是由于 $|S|, |T| \le 5 \times 10^5$，时间和空间都无法接受。

可以注意到，当 $|i - j| > k$ 的时候，$dp_{i, j} > k$，所以只需要考虑 $|i - j| \le k$ 的情况。

重新设 $dp_{i, pos}$ 表示考虑到字符串 $s$ 的第 $i$ 位，字符串 $t$ 的第 $j$ 位时，需要进行的操作次数，令 $pos = j - i + 30$，这样 $pos$ 与 $j$ 就存在一个 一 一 对应的关系，每一对 $(i, j)$ 在 $dp$  数组中都有一个位置进行表示。

时间复杂度： $O(NK)$。

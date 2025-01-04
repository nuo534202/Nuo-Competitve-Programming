# My solution
Contest Link: [Codeforces Round 995](https://codeforces.com/contest/2051)

My Blog Link: [CF995](https://blog.csdn.net/djhws144/article/details/144932791?sharetype=blogdetail&sharerId=144932791&sharerefer=PC&sharesource=djhws144&spm=1011.2480.3001.8118)

## A. Preparing for the Olympiad
当 $a_i > b_{i + 1}$ 时，将 $a_i - b_{i + 1}$ 加入答案。最后将 $a_n$ 加入答案。

时间复杂度： $O(tn)$

## B. Journey
将 $a$, $b$, $c$ 连着三天记为一轮，先算出总共走的完整轮数 $\left\lfloor\frac{n}{a + b + c}\right\rfloor$，最后再算剩下的路程 $n$ % $(a + b + c)$ 需要走多少天。

时间复杂度： $O(t)$

## C. Preparing for the Exam
- 如果 $k < n - 1$，那么不管是什么样的 $list$ 都无法通过。
- 如果 $k = n$，那么可以通过所有的 $list$。
- 如果 $k = n - 1$，那么只有当 $q_{1 \le i \le k}$ 恰好为 $a$ 中没有出现的 $\[1, n\]$ 的整数时可以通过。

时间复杂度： $O(tn)$

## D. Counting Pairs
题目只关心选的两个数的大小，不关心数的位置，所以可以直接对 $a$ 数组进行排序。排序后枚举整数对的第一个数 $l$，第二个数 $r$ 满足 $x \le sum - a[l] - a[r] \le y$，即

$$
\begin{matrix}
a[r] \le sum - a[l] - x \\ 
a[r] \ge sum - a[l] - y
\end{matrix}
$$

时间复杂度： $O(tn\log n)$

## E. Best Price
在购买人数相同（比单价小的 $b$ 数量一定）并且满足不超过 $k$ 个差评的前提下，我们要让单价尽可能的大，因此单价一定为 $a$, $b$ 数组中的某一个值。
因此，只需要枚举 $a$, $b$ 中的每一个值作为商品单价，检查这个单价是否满足不超过 $k$ 个差评的条件，最后算出这个单价下的总利润。

根据题目描述可以发现最终结果与 $a$, $b$ 的顺序无关：

- 是否购买由 $b$ 决定，单价一定的情况下，无论如何调整顺序不会影响购买人数。
- 购买的所有人中，所有人的 $b$ 一定都大于等于单价，因此好评与差评只与 $a$ 的大小有关，无论如何调整 $a$ 数组的顺序， $a$ 与单价之间的大小关系不会改变。

因此可以分别对 $a$, $b$ 数组进行排序。

每次都可以利用二分分别在 $a$, $b$ 数组中差评个数和购买人数，然后直接计算出总利润。

时间复杂度： $O(tn\log n)$

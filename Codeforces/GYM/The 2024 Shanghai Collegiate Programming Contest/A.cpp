#include <bits/stdc++.h>
using namespace std;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
int main() {
    int n = read(), m = read();
    for (int a = 0; a <= n; a++) {
        for (int b = 0; b <= m; b++) {
            int ans = 0;
            for (int c = 0; c <= n; c++) {
                for (int d = 0; d <= m; d++) {
                    if (a == c && b == d) continue;
                    // 正方形面积不为零，所以对角线上的两个点不能重合
                    if ((b + c - a - d) % 2 != 0) continue;
                    int num = (b + c - a - d) / 2;
                    int x1 = a + num, y1 = d + num;
                    int x2 = c - num, y2 = b - num;
                    if (x1 >= 0 && x1 <= n && y1 >= 0 && y1 <= m && x2 >= 0 && x2 <= n && y2 >= 0 && y2 <= m) ans++;
                }
            }
            printf("%d ", ans);
        }
        puts("");
    }
    return 0;
}

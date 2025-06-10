#include <bits/stdc++.h>
using namespace std;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
int main() {
    int n = read(), num = sqrt(n);
    if (n - num * num > num) num++;
    int a[num + 5][num + 5], cnt = 0;
    for (int i = 0; i < num + 5; i++)
        for (int j = 0; j < num + 5; j++) a[i][j] = 0;
    for (int i = 1; i <= num + 1; i++)
        for (int j = 1; j <= num; j++)
            if (cnt < n) a[i][j] = ++cnt;
            else a[i][j] = 0;
    // 将 n 片荷叶尽量排成正方形
    vector<pair<int, int>> v1, v2;
    for (int i = 1; i <= num + 1; i++) {
        for (int j = 1; j <= num; j++) {
            if (a[i][j + 1]) v1.push_back({ a[i][j], a[i][j + 1] }); // 横着走
            if (a[i + 1][j]) v2.push_back({ a[i][j], a[i + 1][j] }); // 竖着走
        }
    }
    int size = min(v1.size(), v2.size());
    printf("%d\n", size);
    for (int i = 0; i < size; i++) printf("%d %d\n", v1[i].first, v1[i].second);
    for (int i = 0; i < size; i++) printf("%d %d\n", v2[i].first, v2[i].second);
    return 0;
}

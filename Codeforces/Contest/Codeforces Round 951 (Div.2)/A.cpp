#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int t, n, a[N];

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

int main() {
    t = read();
    while (t--) {
        int ans = INT_MAX;
        n = read();
        for (int i = 1; i <= n; i++) a[i] = read();

        for (int i = 1; i < n; i++) {
            ans = min(ans, max(a[i], a[i + 1]) - 1);
        }

        printf("%d\n", ans);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int m, n, a, b, c, d, pre[N][N], ab[N][N], cd[N][N];
int rowMin[N][N], colMin[N][N];
int dq[N], front = 1, back = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n >> a >> b >> c >> d;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> pre[i][j];
            pre[i][j] = pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (i >= a && j >= b)
                ab[i][j] = pre[i][j] - pre[i - a][j] - pre[i][j - b] + pre[i - a][j - b];
            if (i > c && i < m && j > d && j < n)
                cd[i][j] = pre[i][j] - pre[i - c][j] - pre[i][j - d] + pre[i - c][j - d];
        }
    }
    for (int i = c + 1; i < m; i++) {
        front = 1, back = 0;
        for (int j = d + 1; j < n; j++) {
            while (front <= back && cd[i][dq[back]] > cd[i][j])
                back--;
            dq[++back] = j;
            while (front <= back && j - dq[front] > b - d - 2)
                front++;
            if (j >= b - 1)
                rowMin[i][j + 1] = cd[i][dq[front]];
        }
    }
    for (int j = b; j <= n; j++) {
        front = 1, back = 0;
        for (int i = c + 1; i < m; i++) {
            while (front <= back && rowMin[dq[back]][j] > rowMin[i][j])
                back--;
            dq[++back] = i;
            while (front <= back && i - dq[front] > a - c - 2)
                front++;
            if (i >= a - 1)
                colMin[i + 1][j] = rowMin[dq[front]][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= a && j >= b) {
                ans = max(ans, ab[i][j] - colMin[i][j]);
            }
        }
    }
    cout << ans << endl
    return 0;
}

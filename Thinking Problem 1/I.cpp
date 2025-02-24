#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m, a[N], b[N], p[N], d[N], len = 1;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i], p[i] = i;
    sort(p + 1, p + m + 1, [&](int x, int y){
        if (a[x] == a[y]) return b[x] > b[y];
        return a[x] < a[y];
    });
    d[1] = b[p[1]];
    for (int i = 2; i <= m; i++) {
        if (b[p[i]] > d[len]) d[++len] = b[p[i]];
        else {
            int l = 1, r = len;
            while (l < r) {
                int mid = l + r >> 1;
                if (d[mid] < b[p[i]]) l = mid + 1;
                else r = mid;
            }
            d[l] = b[p[i]];
        }
    }
    cout << len << '\n';
    return 0;
}
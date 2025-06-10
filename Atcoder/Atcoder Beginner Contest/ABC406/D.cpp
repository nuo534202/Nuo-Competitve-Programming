#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int h, w, n, q;
set<int> row[N], col[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> h >> w >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        row[x].insert(y), col[y].insert(x);
    }
    cin >> q;
    while (q--) {
        int op, idx;
        cin >> op >> idx;
        if (op == 1) {
            cout << row[idx].size() << "\n";
            for (int i : row[idx]) col[i].erase(idx);
            row[idx].clear();
        }
        if (op == 2) {
            cout << col[idx].size() << "\n";
            for (int i : col[idx]) row[i].erase(idx);
            col[idx].clear();
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, q, f[N], pos[N], idx[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) f[i] = pos[i] = idx[i] = i;
    while (q--) {
        int op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            f[a] = idx[b];
        }
        if (op == 2) {
            cin >> a >> b;
            swap(pos[idx[a]], pos[idx[b]]);
            swap(idx[a], idx[b]);
        }
        if (op == 3) {
            cin >> a;
            cout << pos[f[a]] << '\n';
        }
    }
    return 0;
}
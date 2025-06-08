#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, a[N], vis[N];

void op(int x, int y) {
    swap(a[x], a[y]), swap(a[x + 1], a[y + 1]);
    vis[a[x]] = x, vis[a[y]] = y;
    vis[a[x + 1]] = x + 1, vis[a[y + 1]] = y + 1;
}

void solve() {
    cin >> n;
    set<int> odd, even;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], vis[a[i]] = i;
        if (i & 1) odd.insert(a[i]);
        else even.insert(a[i]);
    }
    for (int i = 1; i <= n - 3; i++) {
        if (i & 1) {
            int num = *odd.begin();
            odd.erase(odd.begin());
            if (vis[num] == n) op(n - 3, n - 1);
            op(i, vis[num]);
        } else {
            int num = *even.begin();
            even.erase(even.begin());
            if (vis[num] == n) op(n - 3, n - 1);
            op(i, vis[num]);
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

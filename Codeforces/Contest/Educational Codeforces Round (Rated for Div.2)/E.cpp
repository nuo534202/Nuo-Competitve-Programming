#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int SIZE = 3e6 + 10, N = 15e5; // N 是偏移量，防止结果小于 0
int n, t[SIZE];
string s;

void add(int x, int k) {
    while (x <= 2 * N) {
        t[x] += k;
        x += (x & (-x));
    }
}

int query(int x) {
    int res = 0;
    while (x) {
        res += t[x];
        x -= (x & (-x));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> s;
    s = " " + s;
    int sum = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        add(sum + N, 1);
        if (s[i] == '0') sum++;
        else sum -= 3;
        ans += query(sum + N + 1) - query(sum + N) + query(sum + N - 2);
    }
    cout << ans << endl;
    return 0;
}
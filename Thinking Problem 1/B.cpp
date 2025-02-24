#include <bits/stdc++.h>
using namespace std;

#define double long double

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<double> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    double ans = 1e18;
    cout << fixed << setprecision(8);
    for (int i = 1; i <= n; i++) {
        double x = a[i] / 2;
        ans = min(ans, sum[n] + x * n - (sum[i] + 2 * x * (n - i)));
    }
    cout << ans / n << endl;
    return 0;
}
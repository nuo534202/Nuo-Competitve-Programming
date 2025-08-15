#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    vector<pair<double, double>> v;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        double a = asin(1.0 * y / sqrt(x * x + y * y)), b = asin(1.0 * r / sqrt(x * x + y * y));
        v.push_back({a - b, a + b});
    }
    sort(v.begin(), v.end());
    double res = 0.0, lst = 0.0;
    for (pair<double, double>& p : v) {
        lst = max(lst, p.first);
        res += max(0.0, p.second - lst);
        lst = max(lst, p.second);
    }
    double pi2 = acos(0);
    cout << fixed << setprecision(3) << (pi2 - res) / pi2 << endl;
    return 0;
}

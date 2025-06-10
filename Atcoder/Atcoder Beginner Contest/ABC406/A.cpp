#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * 60 + b >= c * 60 + d) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

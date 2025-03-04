#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool flag = true;
    for (int i = 1; i < n; i++)
        if (a[i] <= a[i - 1]) {
            flag = false;
            break;
        }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
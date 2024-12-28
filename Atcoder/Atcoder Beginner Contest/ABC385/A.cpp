#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a[5];
    for (int i = 1; i <= 3; i++) cin >> a[i];
    sort(a + 1, a + 4);
    if (a[1] + a[2] == a[3] || (a[1] == a[2] && a[2] == a[3])) puts("Yes");
    else puts("No");
    return 0;
}

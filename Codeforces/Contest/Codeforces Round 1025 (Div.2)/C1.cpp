#include <bits/stdc++.h>
using namespace std;

int solve(int i) {
    int res = 0;
    while (i) res += (i % 10), i /= 10;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int res = 0;
    for (int i = 1; i <= 1000000000; i++) {
        int tmp = solve(i);
        tmp = solve(tmp);
        res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}

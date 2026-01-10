#include <iostream>
#include <string>
using namespace std;

const int N = 2e5 + 5;
int n, a[N];
string x, s;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
    return 0;
}
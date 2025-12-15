#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, t, s;
    cin >> m >> t >> s;
    cout << (m * t <= s ? 0 : m - (s + t - 1) / t) << endl;
    return 0;
}
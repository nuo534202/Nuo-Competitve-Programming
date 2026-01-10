#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int n, a[N], p[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], p[i] = i;
    sort(p + 1, p + n + 1, [&](int x, int y){
        return a[x] < a[y];
    });
    cout << p[1] << " " << p[2] << " " << p[3] << endl;
    return 0;
}
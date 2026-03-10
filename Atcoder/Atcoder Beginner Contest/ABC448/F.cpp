#include <bits/stdc++.h>
using namespace std;

const int N = 6e4 + 5;
int n, x[N], y[N], p[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int B = 2e7 / sqrt(N);
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i], p[i] = i;
    sort(p + 1, p + n + 1, [&](int l, int r){
        if (x[l] / B != x[r] / B)
            return x[l] / B < x[r] / B;
        if ((x[l] / B) % 2)
            return y[l] > y[r];
        else
            return y[l] < y[r];
    });
    int pos = 1;
    while (p[pos] != 1)
        pos++;
    for (int i = 0; i < n; i++)
    {
        int idx = pos + i;
        if (idx > n)
            idx -= n;
        cout << p[idx] << " ";
    }
    cout << "\n";
    return 0;
}
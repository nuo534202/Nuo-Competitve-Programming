#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a < x)
        {
            cout << 1 << "\n";
            x = a;
        }
        else
            cout << 0 << "\n";
    }
    return 0;
}
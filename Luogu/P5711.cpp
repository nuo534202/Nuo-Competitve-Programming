#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
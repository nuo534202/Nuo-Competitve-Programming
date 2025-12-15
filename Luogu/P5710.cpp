#include <bits/stdc++.h>
using namespace std;

#define rule1(x) (x % 2 == 0)
#define rule2(x) (x > 4 && x <= 12)
#define out(x) (x ? 1 : 0)

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x;
    cin >> x;
    cout << out(rule1(x) && rule2(x)) << " "
         << out(rule1(x) || rule2(x)) << " "
         << out((rule1(x) && !rule2(x)) || (!rule1(x) && rule2(x))) << " "
         << out(!rule1(x) && !rule2(x)) << endl;
    return 0;
}
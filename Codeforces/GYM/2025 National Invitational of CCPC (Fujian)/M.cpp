#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1 || n == 3 || n == 4 || n == 11)
        cout << "FZU\n";
    else if (n == 2)
        cout << "FNU\n";
    else if (n == 5)
        cout << "FAFU\n";
    else if (n == 6)
        cout << "HQU\n";
    else if (n == 7)
        cout << "MJU\n";
    else if (n == 8)
        cout << "XMUT\n";
    else if (n == 9)
        cout << "QNU\n";
    else if (n == 10)
        cout << "JMU\n";
    return 0;
}
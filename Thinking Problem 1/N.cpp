#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        string s = "";
        cin >> s;
        for (int i = 1; i < s.size(); i += 2) {
            if (s[i] == '0') s[i] = '1';
            else if (s[i] == '1') s[i] = '0';
        }
        int num0 = 0, num1 = 0, num2 = 0;
        for (char c : s)
            num0 += (c == '0'), num1 += (c == '1'), num2 += (c == '2');
        if (num2 > abs(num0 - num1))
            cout << ((num2 - abs(num0 - num1)) & 1) << '\n';
        else
            cout << abs(num0 - num1) - num2 << '\n';
    }
    return 0;
}
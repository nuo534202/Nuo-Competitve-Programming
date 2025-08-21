#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(30, 0);
    string s;
    cin >> s;
    for (char c : s) v[c - 'a']++;
    for (int i = 0; i < 26; i++)
        if (v[i] & 1) {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}

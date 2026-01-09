#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 5;
int n, nxt[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    s = t + " " + s;
    for (int i = 1; i <= 2 * n; i++)
    {
        int j = nxt[i - 1];
        while (j && s[i] != s[j])
            j = nxt[j - 1];
        if (s[i] == s[j])
            j++;
        nxt[i] = j;
    }
    cout << n - nxt[2 * n] << endl;
    return 0;
}
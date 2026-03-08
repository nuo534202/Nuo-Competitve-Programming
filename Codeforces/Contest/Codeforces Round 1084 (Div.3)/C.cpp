#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n, dp[N][N];
string s;

void solve()
{
    cin >> n >> s;
    stack<char> st;
    for (char c : s)
    {
        if (st.empty() || st.top() != c)
            st.push(c);
        else
            st.pop();
    }
    if (st.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
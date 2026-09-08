#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    unordered_map<string, bool> team, signIn;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        team[s] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        string s;
        cin >> s;
        if (team.find(s) == team.end() || team[s] == false)
        {
            cout << "WRONG\n";
        }
        else
        {
            if (signIn.find(s) == signIn.end() || signIn[s] == false)
            {
                cout << "OK\n";
            }
            else
            {
                cout << "REPEAT\n";
            }
        }
        signIn[s] = true;
    }
    return 0;
}
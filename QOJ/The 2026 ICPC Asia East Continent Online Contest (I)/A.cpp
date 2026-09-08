#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<pair<char, int>> input;
    unordered_map<int, int> lst;
    vector<int> pos(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        char c;
        int num;
        cin >> c >> num;
        input.push_back(make_pair(c, num));

        if (c == 'T')
        {
            pos[lst[num]] = i;
        }

        if (c == '+')
        {
            lst[num] = i;
        }
    }

    stack<pair<int, int>> st;
    for (int i = 1; i <= n; i++)
    {
        if (input[i - 1].first == '+')
        {
            st.push(make_pair(input[i - 1].second, pos[i]));
            cout << '+';
        }
        else
        {
            cout << "?";
        }

        while (!st.empty() && st.top().second <= i)
        {
            cout << "-";
            st.pop();
        }
    }
    cout << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
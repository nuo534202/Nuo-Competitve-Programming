#include <bits/stdc++.h>
using namespace std;

int prime_factor(int x)
{
    set<int> s;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            s.insert(i);
            x /= i;
        }
        if (s.size() > 1)
            break;
    }

    if (x > 1)
        s.insert(x);

    if (s.size() > 1)
        return -1;
    if (s.size() == 0)
        return 0;
    return *s.begin();
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    if (is_sorted(a.begin(), a.end()))
    {
        cout << "Bob\n";
        return;
    }
    
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = prime_factor(a[i]);
    
    if (*min_element(b.begin(), b.end()) == -1)
        cout << "Alice\n";
    else if (is_sorted(b.begin(), b.end()))
        cout << "Bob\n";
    else
        cout << "Alice\n";
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
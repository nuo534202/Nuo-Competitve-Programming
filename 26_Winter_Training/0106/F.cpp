#include <bits/stdc++.h>
using namespace std;

typedef size_t idx_t;

const int N = 5e5 + 5;
int nex[N][26], exist[N], cnt;

void insert(const string &s)
{
    int p = 0;
    for (idx_t i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if (!nex[p][c])
            nex[p][c] = ++cnt;
        p = nex[p][c];
        exist[p]++;
    }
}

int find(const string &s)
{
    int p = 0, len = 0;
    for (idx_t i = 0; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if (exist[nex[p][c]] == 1)
            return len;
        p = nex[p][c];
        len++;
    }
    return len;
}

int n;
string s[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        insert(s[i]);
    }
    for (int i = 1; i <= n; i++)
        cout << find(s[i]) << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 5e5 + 5;
int f[N], ans[N];
string s;

int change(int v1, int v2, int xorr)
{
    return (v1 ^ xorr) - (v2 ^ xorr);
}

int nex[N][26], cnt;
int num[N][26];

void insert(string s, int l, int k){
    int p = 0; 
    bool tag = true;
    for(int i = 0; i < l; ++i)
    {
        int c = s[i] - 'a';
        if(!nex[p][c]) nex[p][c] = ++cnt;
        num[p][c] ++;
        if(f[num[p][c]] < i + 1)
        {
            if (tag && num[p][c] == k)
            {
                ans[k] += (i + 1) ^ k;
                tag = false;
            }
            else
            {
                int cg = change(i + 1, f[num[p][c]], num[p][c]);
                ans[k] += cg;
            }
            f[num[p][c]] = i + 1;
        }
        p = nex[p][c];
    }
}


signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> s;
        ans[i] = ans[i - 1];
        insert(s, s.size(), i);
        if (f[i] == 0)
            ans[i] += (f[i] ^ i);
        cout << ans[i] << endl;
    }
    return 0;
}
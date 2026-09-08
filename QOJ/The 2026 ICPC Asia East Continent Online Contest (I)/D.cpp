#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 1e6 + 10, mod = 998244353;
int a[N], cnt[N][2], s[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, ans = 1;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cnt[i][0] = cnt[i-1][0];
        cnt[i][1] = cnt[i-1][1];
        if(cnt[i][0] == cnt[i][1]){
            s[i] = 0;
            cnt[i][s[i]] ++;
            ans = ans * 2 % mod;
        }else{
            if(cnt[i][0] == a[i]){
                s[i] = 1;
                cnt[i][s[i]] ++;
            }else{
                s[i] = 0;
                cnt[i][s[i]] ++;
            }
        }
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll qpow(ll x, ll k, ll mod) {
    ll res = 1LL;
    while (k) {
        if (k & 1) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m;
    cin >> n >> m;
    cout << qpow(10, n, m * m) / m << endl;
    return 0;
}
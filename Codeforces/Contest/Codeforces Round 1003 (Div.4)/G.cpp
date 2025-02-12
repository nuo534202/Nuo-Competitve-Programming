#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> prime;
constexpr int N = 2e5 + 10;
int a[N], cnt[N], vis[N];
bool not_prime[N];

void is_prime() {
    memset(not_prime, false, sizeof(not_prime));
    not_prime[1] = true;
    for (int i = 2; i <= 200000; i++) {
        if (not_prime[i] == false) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] <= 200000; j++) {
            not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve() {
    int n; cin >> n;
    memset(cnt, 0, sizeof(cnt)), memset(vis, 0, sizeof(vis));
    ll ans = 0LL;
    int tot = 0, num = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (!not_prime[a[i]]) tot++;
    }
    for (int i = 1; i <= n; i++) {
        if (!not_prime[a[i]]) {
            if (!vis[a[i]]) {
                ans += 1LL * cnt[a[i]] * (tot - cnt[a[i]] - num);
                num += cnt[a[i]], vis[a[i]] = 1;
            }
        } else {
            if (!vis[a[i]]) {
                for (int j = 0; j < prime.size(); j++) {
                    if (prime[j] * prime[j] > a[i]) break;
                    if (a[i] % prime[j] == 0) {
                        if (not_prime[a[i] / prime[j]]) break;
                        ans += 1LL * cnt[a[i]] * (cnt[a[i]] + 1) / 2;
                        if (prime[j] == a[i] / prime[j])
                            ans += 1LL * cnt[a[i]] * cnt[prime[j]];
                        else
                            ans += 1LL * cnt[a[i]] * (cnt[prime[j]] + cnt[a[i] / prime[j]]);
                        break;
                    }
                }
                vis[a[i]] = 1;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    is_prime();
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
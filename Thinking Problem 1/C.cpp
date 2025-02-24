#include <bits/stdc++.h>
using namespace std;

#define int long long

using ll = long long;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> v(5);
    for (int i = 1; i <= 2 * n; i++) {
        ll a; char c;
        cin >> a >> c;
        if (c == 'R') v[1].push_back(a);
        if (c == 'G') v[2].push_back(a);
        if (c == 'B') v[3].push_back(a);
    }
    int pos1 = 0, pos2 = 0;
    for (int i = 1; i <= 3; i++)
        if (v[i].size() & 1) {
            pos1 = i;
            break;
        }
    for (int i = pos1 + 1; i <= 3; i++)
        if (v[i].size() & 1) {
            pos2 = i;
            break;
        }
    if (!pos1 && !pos2) {
        cout << 0 << endl;
        return 0;
    }
    sort(v[1].begin(), v[1].end()), sort(v[2].begin(), v[2].end()), sort(v[3].begin(), v[3].end());
    ll ans = LLONG_MAX;
    int pos = pos1 ^ pos2;
    for (int i = 0; i < (int)v[pos1].size(); i++) {
        int idx2 = lower_bound(v[pos2].begin(), v[pos2].end(), v[pos1][i]) - v[pos2].begin();
        idx2 = min(idx2, (int)v[pos2].size() - 1);
        idx2 = max(idx2, 0LL);
        if (idx2 > 0) ans = min(ans, min(abs(v[pos2][idx2] - v[pos1][i]), abs(v[pos2][idx2 - 1] - v[pos1][i])));
        else ans = min(ans, abs(v[pos2][idx2] - v[pos1][i]));
    }
    vector<pair<ll, int>> tmp1, tmp2;
    for (int i = 0; i < (int)v[pos].size(); i++) {
        int idx1 = lower_bound(v[pos1].begin(), v[pos1].end(), v[pos][i]) - v[pos1].begin();
        int idx2 = lower_bound(v[pos2].begin(), v[pos2].end(), v[pos][i]) - v[pos2].begin();
        idx1 = min(idx1, (int)v[pos1].size() - 1), idx2 = min(idx2, (int)v[pos2].size() - 1);
        idx1 = max(idx1, 0LL), idx2 = max(idx2, 0LL);
        if (idx1 > 0) tmp1.push_back({min(abs(v[pos1][idx1] - v[pos][i]), abs(v[pos1][idx1 - 1] - v[pos][i])), i});
        else tmp1.push_back({abs(v[pos1][idx1] - v[pos][i]), i});
        if (idx2 > 0) tmp2.push_back({min(abs(v[pos2][idx2] - v[pos][i]), abs(v[pos2][idx2 - 1] - v[pos][i])), i});
        else tmp2.push_back({abs(v[pos2][idx2] - v[pos][i]), i});
    }
    if (v[pos].size()) {
        sort(tmp1.begin(), tmp1.end()), sort(tmp2.begin(), tmp2.end());
        if (tmp1[0].second != tmp2[0].second) ans = min(ans, tmp1[0].first + tmp2[0].first);
        else ans = min(ans, min(tmp1[0].first + tmp2[1].first, tmp1[1].first + tmp2[0].first));
    }
    cout << ans << endl;
    return 0;
}
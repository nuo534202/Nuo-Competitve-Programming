#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector<pair<int, int>> v;
    vector<int> vis(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            int pos;
            cin >> pos;
            v.push_back({ pos, i });
        }
    }
    sort(v.begin(), v.end());
    // for (auto& [x, y] : v)
    //     cout << x << " " << y << endl;
    // cout << endl;
    queue<int> q;
    int ans = INT_MAX;
    bool flag = false;
    for (int i = 0; i < (int)v.size(); i++) {
        q.push(i);
        vis[v[q.back()].second]++;
        if (!flag && vis[v[q.back()].second] == 1) {
            bool cur = true;
            for (int j = 1; j <= k; j++)
                if (!vis[j]) {
                    cur = false;
                    break;
                }
            flag = cur;
        }
        if (flag)
            while (q.size() > k && vis[v[q.front()].second] > 1)
                vis[v[q.front()].second]--, q.pop();
        if (flag)
            ans = min(ans, v[q.back()].first - v[q.front()].first);
        // cout << q.front() << " " << q.back() << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
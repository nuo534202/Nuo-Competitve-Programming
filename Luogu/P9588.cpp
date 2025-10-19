#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
int q, c, del = 0, cur = 1, val[N], pre[N], cnt = 0;

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> q;
    multiset<int> s;
    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            cnt++;
            val[cnt] = x, pre[cnt] = pre[cnt - 1] + x;
            s.insert(x);
        }
        if (op == 2) {
            cin >> x;
            del += x;
            while (cur <= cnt && pre[cur] <= del)
                s.erase(s.find(val[cur++]));
        }
        if (op == 3) {
            cin >> x;
            int pos = lower_bound(pre + 1, pre + cnt + 1, x + del) - pre;
            cout << x + del - pre[pos - 1] << '\n';
        }
        if (op == 4) {
            cout << *s.rbegin() << '\n';
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, k, st[N], ans[N], pre[N], top = 0, cnt = 0;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        st[++top] = i;
        pre[top] = pre[top - 1] + (s[i] == 'c');
        if (top >= k + 1 && pre[top] - pre[top - k - 1] == 1) {
            for (int i = top; i >= top - k; i--)
                ans[++cnt] = st[i] + 1;
            top -= (k + 1);
        }
        if (top == 0) {
            for (int i = cnt; i; i--) {
                cout << ans[i];
                if (i % (k + 1) == 1) cout << endl;
                else cout << " ";
            }
            cnt = 0;
        }
    }
    for (int i = cnt; i; i--) {
        cout << ans[i];
        if (i % (k + 1) == 1) cout << endl;
        else cout << " ";
    }
    return 0;
}
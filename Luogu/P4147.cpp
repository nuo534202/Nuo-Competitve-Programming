#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, row[N][N], up[N], down[N];
char c[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[i][j] == 'R') row[i][j] = 0;
            else row[i][j] = row[i][j - 1] + 1;
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && row[st.top()][j] >= row[i][j]) {
                down[st.top()] = i;
                st.pop();
            }
            up[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
        while (!st.empty()) {
            down[st.top()] = n + 1;
            st.pop();
        }
        for (int i = 1; i <= n; i++)
            ans = max(ans, (down[i] - up[i] - 1) * row[i][j]);
    }
    cout << ans * 3 << endl;
    return 0;
}

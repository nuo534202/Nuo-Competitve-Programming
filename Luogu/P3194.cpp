#include <bits/stdc++.h>
using namespace std;

#define eps 1e-8

const int N = 5e4 + 5;
int n, a[N], b[N], p[N], st[N], top = 0;

double ints(int x, int y) {
    return (double)(b[x] - b[y]) / (double)(a[y] - a[x]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i], p[i] = i;
    sort(p + 1, p + n + 1, [&](int x, int y){
        if (a[x] == a[y]) return b[x] > b[y];
        return a[x] < a[y];
    });
    st[++top] = p[1];
    for (int i = 2; i <= n; i++) {
        if (a[p[i]] != a[p[i - 1]]) {
            while (top >= 2 && ints(st[top - 1], st[top]) >= ints(st[top], p[i]))
                top--;
            st[++top] = p[i];
        }
    }
    sort(st + 1, st + top + 1);
    for (int i = 1; i <= top; i++) {
        cout << st[i];
        if (i < top) cout << " ";
        else cout << endl;
    }
    return 0;
}
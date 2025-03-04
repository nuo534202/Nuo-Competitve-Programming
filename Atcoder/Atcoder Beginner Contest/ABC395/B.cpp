#include <bits/stdc++.h>
using namespace std;

char s[55][55];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int j = n - i + 1;
        if (i <= j) {
            char c;
            if (i & 1) c = '#';
            else c = '.';
            for (int x = i; x <= j; x++)
                for (int y = i; y <= j; y++) s[x][y] = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}
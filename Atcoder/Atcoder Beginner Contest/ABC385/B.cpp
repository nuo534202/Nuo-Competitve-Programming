#include <bits/stdc++.h>
using namespace std;

int h, w, x, y, vis[105][105];
string s[150], t;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> h >> w >> x >> y;
  for (int i = 1; i <= h; i++) {
    cin >> s[i];
    s[i] = " " + s[i];
  }
  cin >> t;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == 'U') {
      int xx = x - 1, yy = y;
      if (s[xx][yy] != '#') x = xx, y = yy, vis[xx][yy] = 1;
    }
    if (t[i] == 'D') {
      int xx = x + 1, yy = y;
      if (s[xx][yy] != '#') x = xx, y = yy, vis[xx][yy] = 1;
    }
    if (t[i] == 'L') {
      int xx = x, yy = y - 1;
      if (s[xx][yy] != '#') x = xx, y = yy, vis[xx][yy] = 1;
    }
    if (t[i] == 'R') {
      int xx = x, yy = y + 1;
      if (s[xx][yy] != '#') x = xx, y = yy, vis[xx][yy] = 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++)
      if (vis[i][j] && s[i][j] == '@') ans++;
  cout << x << ' ' << y << ' ' << ans << endl;
  return 0;
}

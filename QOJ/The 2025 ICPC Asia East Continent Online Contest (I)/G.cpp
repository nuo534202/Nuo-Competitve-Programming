#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, vis[N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (b == a + 1) vis[a] = 1;
	}
	bool flag = true;
	for (int i = 1; i < n; i++)
		if (!vis[i]) flag = false;
	cout << (flag ? "Yes\n" : "No\n");
	return 0;
}

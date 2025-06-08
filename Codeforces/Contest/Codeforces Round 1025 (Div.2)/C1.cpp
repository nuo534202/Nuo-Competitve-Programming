#include <bits/stdc++.h>
using namespace std;

int ask(const string &op, int y) {
	if (op == "digit" || op == "!") cout << op << endl;
	else cout << op << " " << y << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

void solve() {
	int n;
	cin >> n;
	ask("digit", 0), ask("digit", 0);
	ask("add", -8);
	ask("add", -4);
	ask("add", -2);
	ask("add", -1);
	ask("add", n - 1);
	ask("!", 0);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

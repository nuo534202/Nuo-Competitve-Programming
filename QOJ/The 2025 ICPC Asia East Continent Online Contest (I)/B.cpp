#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cout << i;
		if (i < k) cout << " ";
		else cout << endl;
	}
	return 0;
}

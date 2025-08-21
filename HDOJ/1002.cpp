#include <bits/stdc++.h>
using namespace std;

void solve() {
	string A, B;
	cin >> A >> B;
	int len = max(A.size(), B.size()) + 5;
	vector<int> a(len + 1), b(len + 1);
	for (int i = A.size() - 1, j = 1; i >= 0 && j <= len; i--, j++)
		a[j] = A[i] - '0';
	for (int i = B.size() - 1, j = 1; i >= 0 && j <= len; i--, j++)
		b[j] = B[i] - '0';
	for (int i = 1; i <= len; i++) {
		a[i] += b[i];
		if (a[i] > 9) a[i] -= 10, a[i + 1]++;
	}
	int pos = len;
	for (; pos; pos--) {
		if (a[pos]) break;
	}
	cout << A << " + " << B << " = ";
	for (int i = pos; i; i--) cout << a[i];
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case " << i << ":\n";
		solve();
		if (i < T) cout << "\n";
	}
  return 0;
}

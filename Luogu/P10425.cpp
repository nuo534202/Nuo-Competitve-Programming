#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n, a[N], len;
string q;

void pw2() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= len; j++)
			a[j] *= 2;
		for (int j = 1; j <= len; j++)
			a[j + 1] += a[j] / 10, a[j] %= 10;
		if (a[len + 1]) len++;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	memset(a, 0, sizeof(a));
	reverse(q.begin(), q.end());
	int pos = q.find('.');
	q.erase(pos, 1);
	for (int i = 0; i < (int)q.size(); i++)
		a[i + 1] = q[i] - '0';
	len = q.size();
	pw2();
	if (a[pos] >= 5) a[pos + 1]++;
	for (int i = pos + 1; i <= len; i++)
		a[i + 1] += a[i] / 10, a[i] %= 10;
	if (a[len + 1]) len++;
	for (int i = len; i > pos; i--) cout << a[i];
	cout << endl;
	return 0;
}

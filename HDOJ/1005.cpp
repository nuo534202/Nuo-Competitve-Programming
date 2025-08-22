#include <bits/stdc++.h>
using namespace std;

const int mod = 7;
int x[5][5], res[5][5], tmp[5][5];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, a, b;
	while (1) {
		cin >> a >> b >> n;
		if (!n && !a && !b) break;
		x[1][1] = a % mod, x[1][2] = b % mod, x[2][1] = 1, x[2][2] = 0;
		res[1][1] = res[2][2] = 1, res[1][2] = res[2][1] = 0;
		if (n <= 2) {
			cout << 1 << "\n";
			continue;
		}
		n -= 2;
		while (n) {
			if (n & 1) {
				tmp[1][1] = tmp[2][2] = tmp[1][2] = tmp[2][1] = 0;
				for (int i = 1; i <= 2; i++)
					for (int j = 1; j <= 2; j++)
						for (int k = 1; k <= 2; k++)
							tmp[i][j] += res[i][k] * x[k][j];
				for (int i = 1; i <= 2; i++)
					for (int j = 1; j <= 2; j++)
						res[i][j] = tmp[i][j] % mod;
			}
			tmp[1][1] = tmp[2][2] = tmp[1][2] = tmp[2][1] = 0;
			for (int i = 1; i <= 2; i++)
				for (int j = 1; j <= 2; j++)
					for (int k = 1; k <= 2; k++)
						tmp[i][j] += x[i][k] * x[k][j];
			for (int i = 1; i <= 2; i++)
				for (int j = 1; j <= 2; j++)
					x[i][j] = tmp[i][j] % mod;

			n >>= 1;
		}
		cout << (res[1][1] + res[1][2]) % mod << "\n";
	}
	return 0;
}

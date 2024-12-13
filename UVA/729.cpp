#include<bits/stdc++.h>
using namespace std;

int pw[20];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i < 20; i++) pw[i] = pw[i - 1] * 2;
	int n, N, H;
	cin >> n;
	while (n--) {
		cin >> N >> H;
		for (int i = 1; i < pw[N]; i++) {
			int tmp = i, num = 0;
			string s = "";
			while (tmp) num += (tmp & 1), s += (tmp & 1) + '0', tmp >>= 1;
			if (num == H) {
				while (s.size() < N) s += '0';
				string str = "";
				for(int i = 0; i < s.size(); i++) {
					str.push_back(s[s.size() - i - 1]);
				}
				cout << str << '\n';
			}
		}
		if (n) cout << '\n';
	}
	return 0;
}

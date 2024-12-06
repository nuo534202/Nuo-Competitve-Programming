#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 10;
int q, vis[N], num = 0;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
int main() {
	for (int i = 0; i <= 1000000; i++) vis[i] = 0;
	q = read();
	for (int i = 1; i <= q; i++) {
		int opt = read();
		if (opt == 3) printf("%d\n", num);
		else {
			int x = read();
			if (opt == 1) {
				if (!vis[x]) num++;
				vis[x]++;
			}
			if (opt == 2) {
				vis[x]--;
				if (!vis[x]) num--;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
int main() {
	int n = read();
	while (n--) {
		int a = read(), b = read(), c = read();
		priority_queue<int, vector<int>, greater<int>> q;
		q.push(a), q.push(b), q.push(c);
		for (int i = 1; i <= 5; i++) {
			int num = q.top() + 1;
			q.pop();
			q.push(num);
		}
		int ans = 1;
		while (q.size()) {
			ans *= q.top();
			q.pop();
		}
		printf("%d\n", ans);
	}
	return 0;
}
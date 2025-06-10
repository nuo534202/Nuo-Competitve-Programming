#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 10;
char s[10] = "shanghai", str[N];
int vis[30];
 
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
 
int main() {
	int n = read();
    scanf("%s", str);
	for (int i = 0; i < 30; i++) vis[i] = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 'a' - 'A';
		vis[str[i] - 'a']++;
	}
	int ans = INT_MAX;
	for (int i = 0; i < 8; i++) {
		if (s[i] == 'a' || s[i] == 'h') continue;
		ans = min(ans, vis[s[i] - 'a']);
	}
	ans = min(ans, min(vis['a' - 'a'], vis['h' - 'a']) / 2);
	printf("%d", ans);
	return 0;
}

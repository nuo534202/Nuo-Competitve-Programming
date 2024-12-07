#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int t, n, m, k, f[N];
string s;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
int main() {
    t = read();
    while (t--) {
        n = read(), m = read(), k = read();
        cin >> s;
        s = "L" + s; // 左岸与木头 'L' 性质相同，因此把左岸处理成 'L'
        f[n + 1] = 0;
        for(int i = n; i; i--) f[i] = N;
        f[0] = N;
        for(int i = n; i >= 0; i--)
        {
            if(s[i] == 'C') continue;
            if(s[i] == 'L')
                for(int j = 1; j <= m && i + j <= n + 1; j++) f[i] = min(f[i + j], f[i]);
            	// 根据原题意理解，可以从当前位置往后跳到任何 m 以内且 s[i] != 'C' 的位置
            	// 由于从左往右跳跟从右往左跳必定存在相同路径
            	// 反向考虑之后，变成了可以从后面长度 m 以内任意 s[i] != 'C' 的位置往前跳
            if (s[i] == 'W') f[i] = f[i + 1] + 1;
        }
        if(f[0] <= k) puts("YES");
        else puts("NO");
    }
	return 0;
}
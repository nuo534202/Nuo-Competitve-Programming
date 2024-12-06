#include <bits/stdc++.h>
using namespace std;
 
int n, len = 0;
string s[105];
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		int size = s[i].size();
		len = max(len, size); // 记录最大长度
	}
	for (int i = 0; i < len; i++) {
		int num = 0;
		for (int j = n; j; j--) {
			int size = s[j].size();
			if (i < size) {
				for (int i = 1; i <= num; i++) putchar('*');
				num = 0;
				putchar(s[j][i]);
			}
			else num++; // 避免*出现在字符串末尾
		}
		putchar('\n');
	}
	return 0;
}
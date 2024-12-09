#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int N = 5e5 + 10;
int n, ans = 0LL, t[N];
struct node { int m, num; } a[N]; // m 存读入的数字, num 存数字的位置
 
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >='0' && c <='9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
 
bool cmp(node x, node y) {
    if (x.m == y.m) return x.num > y.num;
    return x.m > y.m;
}
 
int lowbit(int x) { return x & (-x); }
 
void add(int x, int k) {
    while (x <= n) {
        t[x] += k;
        x += lowbit(x);
    }
}

int sum(int x) {
    int oup = 0LL;
    while (x > 0) {
        oup += t[x];
        x -= lowbit(x);
    }
    return oup;
}
 
signed main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i].m = read();
        a[i].num = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1;i <= n; i++) {
        add(a[i].num, 1);
        ans += sum(a[i].num - 1);
    }
    cout<<ans<<endl;
    return 0;
}

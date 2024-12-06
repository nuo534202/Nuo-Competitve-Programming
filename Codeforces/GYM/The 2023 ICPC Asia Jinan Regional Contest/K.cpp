#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define inf 1000000000
 
const int N = 5e5 + 10;
int n, k, a[N], L, R, M;
bool isodd;
multiset<int> sl, sr;
 
void add(int x) {
	if (isodd) {
		if (M < x) {
			L += M, R += x;
			sl.insert(M), sr.insert(x);
		} else {
			L += x, R += M;
			sl.insert(x), sr.insert(M);
		}
	} else {
		int A = *(prev(sl.end())), B = *(sr.begin());
		if (A <= x && x <= B) M = x;
		else if (x < A) {
			L += x - A, M = A;
			sl.insert(x), sl.erase(sl.find(A));
		} else {
			R += x - B, M = B;
			sr.insert(x), sr.erase(sr.find(B));
		}
	}
	isodd = !isodd;
}
 
void remove(int x) {
	if (isodd) {
		if (x < M) {
			L += M - x;
			sl.erase(sl.find(x)), sl.insert(M);
		} else if (x > M) {
			R += M - x;
			sr.erase(sr.find(x)), sr.insert(M);
		}
	} else {
		int A = *(prev(sl.end())), B = *(sr.begin());
		if (x <= A) {
			L -= x, R -= B, M = B;
			sl.erase(sl.find(x)), sr.erase(sr.find(B));
		} else if (x >= B) {
			L -= A, R -= x, M = A;
			sl.erase(sl.find(A)), sr.erase(sr.find(x));
		}
	}
	isodd = !isodd;
}
 
signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		L = R = M = 0, isodd = false;
		sl.insert(-inf), sr.insert(inf); // 防止后续访问越界
		for (int i = 1; i <= n; i++) cin >> a[i], a[i] -= i;
		int l = 1, ans = 0;
		for (int r = 1; r <= n; r++) {
			add(a[r]);
			while (l < r && R - L > k) {
				remove(a[l]);
				l++;
			}
			ans = max(ans, r - l + 1);
		}
		sl.clear(), sr.clear();
		cout << ans << '\n';
	}
    return 0;
}

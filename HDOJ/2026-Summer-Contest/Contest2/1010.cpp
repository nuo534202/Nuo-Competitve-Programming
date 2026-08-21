#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node;
int diff(const Node &x);

struct Node
{
    int len, num;
    bool operator<(const Node &x) const
    {
        return diff(*this) < diff(x);
    }
};

int cal(int len, int x)
{
    int act_len = len - x + 1;
    int min_len = act_len / x;
    int max_len = min_len + 1;
    int max_len_num = act_len - min_len * x;
    return max_len_num * f(max_len) + (x - max_len_num) * f(min_len);
}

int diff(const Node &x)
{
    return cal(x.len, x.num) - cal(x.len, x.num + 1);
}

// len - num / num

inline int f(int x)
{
    return 20 + 5 * x;
}

void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    priority_queue<Node> pq;

    Node node;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '1')
        {
            if (node.len)
                pq.push(node);
            node.len = 0, node.num = 1;
        }
        else
            node.len++;
    }
    
    while (k--)
    {
        node = pq.top();
        pq.pop();
        node.num++;
        if (node.len > node.num)
            pq.push(node);
    }

    int ans = 0;
    while (!pq.empty())
    {
        node = pq.top();
        pq.pop();
        ans += cal(node.len, node.num);
    }

    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
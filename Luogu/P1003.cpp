#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
    int a, b, g, k;
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<Rectangle> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].a >> v[i].b >> v[i].g >> v[i].k;
    int x, y;
    cin >> x >> y;
    int id = -1;
    for (int i = 0; i < n; i++)
    {
        if (x >= v[i].a && x <= v[i].a + v[i].g &&
            y >= v[i].b && y <= v[i].b + v[i].k)
        {
            id = i + 1;
        }
    }
    cout << id << endl;
    return 0;
}
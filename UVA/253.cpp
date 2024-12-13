#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> en = {{1, 2, 4}, {1, 4, 5}, {1, 5, 3}, {1, 3, 2},
                          {2, 4, 1}, {2, 1, 3}, {2, 3, 6}, {2, 6, 4},
                          {3, 2, 1}, {3, 1, 5}, {3, 5, 6}, {3, 6, 2},
                          {4, 2, 6}, {4, 6, 5}, {4, 5, 1}, {4, 1, 2},
                          {5, 4, 6}, {5, 6, 3}, {5, 3, 1}, {5, 1, 4},
                          {6, 2, 3}, {6, 3, 5}, {6, 5, 4}, {6, 4, 2}
};
int comp[3] = {1, 2, 4}, shoot[10] = {0, 6, 5, 4, 3, 2, 1};
int main() {
    string str;
    while (cin >> str) {
        string str1 = " " + str.substr(0, 6), str2 = " " + str.substr(6, 6);
        bool all_ok = false;
        for (int i = 0; i < en.size(); i++) {
            bool ok = true;
            for (int j = 0; j < 3; j++) {
                int num1 = en[i][j], num2 = comp[j];
                if (str1[num1]!= str2[num2] || str1[shoot[num1]] != str2[shoot[num2]]) ok = false;
            }
            if (ok) {
                all_ok = true;
                break;
            }
        }
        if (all_ok) puts("TRUE");
        else puts("FALSE");
    }
    return 0;
}

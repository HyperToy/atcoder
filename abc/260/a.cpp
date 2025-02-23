#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    map<char, int> mp;
    for (char c : S) mp[c]++;
    for (auto p : mp) {
        if (p.second == 1) {
            cout << p.first << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

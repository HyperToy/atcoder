#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    string s;
    cin >> s;
    int l = s.length();

    bool alla = true;
    bool allz = true;
    for (char c : s) {
        alla = alla && c == 'a';
        allz = allz && c == 'z';
    }
    if (allz) {
        if (l == 20) {
            cout << "NO" << endl;
        } else {
            s[0]--;
            cout << s + "a" << endl;
        }
        return 0;
    }
    if (alla) {
        if (l == 1) {
            cout << "NO" << endl;
        } else {
            s[l-1]++;
            cout << s.substr(1) << endl;
        }
        return 0;
    }

    rep(i,l) rep(j,l) {
        if (i == j) continue;
        if (s[i] != 'a' && s[j] != 'z') {
            s[i]--;
            s[j]++;
            cout << s << endl;
            return 0;
        } 
    }

    s[0]--;
    cout << s + "a" << endl;
    return 0;
}
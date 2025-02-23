#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string s;
    cin >> s;
    int l = s.length();
    rep(i,l) if (s[i] == '0') s[i] = '2';
    rep(i,l) if (s[i] == '1') s[i] = '0';
    rep(i,l) if (s[i] == '2') s[i] = '1';
    cout << s << endl;
}

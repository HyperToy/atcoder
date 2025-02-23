#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string S;
    cin >> S;
    int l = S.length();
    bool ok = !(l & 1);
    rep(i,l) {
        if (i & 1) ok = ok && S[i] == 'i';
        else ok = ok && S[i] == 'h';
    }
    cout << (ok ? "Yes" : "No") << endl;
}
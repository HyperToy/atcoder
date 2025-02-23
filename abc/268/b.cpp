#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    string S, T;
    cin >> S >> T;
    int l = S.length();
    bool ok = l <= T.length();
    if (ok) rep(i,l) if (S[i] != T[i]) ok = false;
    cout << (ok ? "Yes" : "No") << endl;
} 
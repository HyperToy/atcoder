#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    string s;
    cin >> N >> s;
    int r = 0;
    rep(i,N) {
        if (s[i] == 'R') r++;
        else r--;
    }
    if (r > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
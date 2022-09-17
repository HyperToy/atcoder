#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int n = 10;
    string s[n];
    rep(i,n) cin >> s[i];

    rep(a,n) rep(c,n) {
        if (s[a][c] != '#') continue;
        if (a > 0 && s[a-1][c] != '.') continue;
        if (c > 0 && s[a][c-1] != '.') continue;
        rep(b,n) rep(d,n) {
            if (b < a) continue;
            if (d < c) continue;
            if (s[b][d] != '#') continue;
            if (b < n-1 && s[b+1][d] != '.') continue;
            if (d < n-1 && s[b][d+1] != '.') continue;
            printf("%d %d\n%d %d\n", a+1, b+1, c+1, d+1);
            return 0;
        }
    }
} 
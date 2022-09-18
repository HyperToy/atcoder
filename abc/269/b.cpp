#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;

int main(){
    int n = 10;
    string s[n];
    rep(i,n) cin >> s[i];

    int a = INF, b = -INF, c = INF, d = -INF;
    rep(i,n) rep(j,n) {
        if (s[i][j] == '#') {
            a = min(a, i+1);
            b = max(b, i+1);
            c = min(c, j+1);
            d = max(d, j+1);
        }
    }
    printf("%d %d\n%d %d\n", a, b, c, d);
} 
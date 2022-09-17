#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int ask(int a, int b, int c, int d) {
    printf("? %d %d %d %d\n", a, b, c, d);
    int t;
    cin >> t;
    return t;
}

int main(){
    int N;
    cin >> N;
    
    int xl = 1;
    int xr = N + 1;
    while (xl + 1 < xr) {
        int m = (xl + xr) / 2;
        int t = ask(xl, m-1, 1, N);
        if (t == m - xl) xl = m;
        else xr = m;
    }

    int yl = 1;
    int yr = N + 1;
    while (yl + 1 < yr) {
        int m = (yl + yr) / 2;
        int t = ask(1, N, yl, m-1);
        if (t == m - yl) yl = m;
        else yr = m;
    }

    printf("! %d %d\n", xl, yl);
} 
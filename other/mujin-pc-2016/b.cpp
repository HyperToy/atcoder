#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
#define PI acos(-1)

double circle(int radius) {
    return PI * radius * radius;
}

int main(){
    int a[3];
    rep(i,3) cin >> a[i];
    
    int R = 0;
    int r = 0;
    rep(i,3) {
        R += a[i];
        r = max(r, a[i] - a[(i+1) % 3] - a[(i+2) % 3]);
    }
    double ans = circle(R) - circle(r);
    
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int P = 0;
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int ans = -1;
    if (abs(X) < abs(Y) || X * Y < 0) {
        ans = abs(X);
    } else {
        if (abs(Z) < abs(Y) || Z * Y < 0) {
            ans = abs(Z) + abs(X - Z);
        } 
    }
    cout << ans << endl;
}
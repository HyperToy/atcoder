#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    ll X, K;
    cin >> X >> K;
    ll m = 1;
    rep(i,K) {
        if (X % 10 >= 5) {
            X /= 10;
            X++;
        } else {
            X /= 10;
        }
        m *= 10;
    }
    cout << X * m << endl;
}

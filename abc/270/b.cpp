#include <bits/stdc++.h>
using namespace std;

int main(){
    int P = 0;
    int X, Y, Z;
    cin >> X >> Y >> Z;

    if (Y < 0) {
        X *= -1;
        Y *= -1;
        Z *= -1;
    }

    int ans = -1;
    if (X < Y) {
        ans = abs(X);
    } else {
        if (Z < Y) {
            ans = abs(Z) + abs(X - Z);
        } 
    }

    cout << ans << endl;
}
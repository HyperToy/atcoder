/*
    B - Ringo's Favorite Numbers
    2021.09.07
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int d, n;
    cin >> d >> n;
    
    if (n == 100) n++;
    int ans;
    if (d == 0) ans = n;
    else if (d == 1) ans = n * 100;
    else ans = n * 10000;

    cout << ans << endl;
} 
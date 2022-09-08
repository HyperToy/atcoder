#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ans;
    if (a == b) ans = x;
    else if (a > b) ans = min(y, x * 2) * (a - b - 1) + x;
    else ans = min(y, x * 2) * (b - a) + x;
    cout << ans << endl;
} 
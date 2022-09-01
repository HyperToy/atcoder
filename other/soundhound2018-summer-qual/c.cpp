#include <bits/stdc++.h>
using namespace std;
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    double n, m, d;
    cin >> n >> m >> d;
    double ans;
    if (d > 0) ans = 2 * (n - d) / n / n * (m - 1);
    else ans = 1 / n * (m - 1);
    cout << fixed << setprecision(10);
    cout << ans << endl;
} 
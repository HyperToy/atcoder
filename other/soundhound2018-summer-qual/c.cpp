#include <bits/stdc++.h>
using namespace std;
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    double n, m, d;
    cin >> n >> m >> d;
    double ans = (min(n, 2 * d) + 2 * max(n - 2 * d, 0.0)) / n / n * (m - 1);
    if (abs(d) < 1e-3) ans = 1 / n * (m - 1);
    cout << fixed << setprecision(10);
    cout << ans << endl;
} 
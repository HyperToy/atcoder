#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    double n, k;
    cin >> n >> k;

    double ans = 0.0;
    for (double i = 1.0; i <= min(n, k-1); i++) {
        double now = 1.0;
        double num = i;
        while (num < k) {
            num *= 2.0;
            now *= 2.0;
        }
        ans += 1.0 / now;
    }
    ans /= n;
    if (n >= k) {
        ans += (n-k+1.0) / n;
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}
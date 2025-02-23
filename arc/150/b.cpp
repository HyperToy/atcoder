#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

void solve() {
    ll a, b;
    cin >> a >> b;
    if (b % a == 0) {
        cout << 0 << endl;
        return;
    }
    ll p = b / a;
    ll ans = a * (p + 1) - b;
    for (; p > 0; p--) {
        ll x = (b + p - 1) / p - a;
        ll y = (a + x) * p - b;
        if (x > ans) break;
        ans = min(ans, x + y);
    }
    cout << ans << endl;
    return;
}

int main(){
    int T;
    cin >> T;
    while (T--) solve();
}

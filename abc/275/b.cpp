#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    vector<ll> a(6);
    rep(i,6) cin >> a[i];

    ll mod = 998244353;
    ll x = 1;
    ll y = 1;
    rep(i,3) {
        (x *= a[i] % mod) %= mod;
        (y *= a[i + 3] % mod) %= mod;
    }
    ll ans = (x + mod - y) % mod;
    cout << ans << endl;
}

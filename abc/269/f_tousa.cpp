#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

#define mod 998244353
#define inv2 499122177 // inverse of 2

// 初項a, 公差d, 項数n の等差数列の和
ll alithmetic_sum(ll a, ll d, ll n) {
    ll l = (a + d * (n - 1)) % mod;
    ll res = (a + l) % mod;
    (res *= n) %= mod;
    (res *= inv2) %= mod;
    return res;
}

ll m;

pair<ll, ll> row_sum_num(ll x, ll l, ll r) {
    if ((x + l) % 2 == 1) l++;
    if ((x + r) % 2 == 1) r--;
    if (l > r) return {0, 0};

    ll a = ((x - 1) * m + l) % mod;
    ll num = (r - l) / 2 + 1;
    ll sum = alithmetic_sum(a, 2, num);

    ll diff = num * 2 % mod * m % mod;
    return {sum, diff};
}

int main(){
    ll n;
    cin >> n >> m;
    int q;
    cin >> q;
    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        auto row0 = row_sum_num(a, c, d);
        auto row1 = row_sum_num(a+1, c, d);
        ll cnt0 = (b - a + 1) / 2;
        ll cnt1 = cnt0;
        if ((b - a + 1) % 2 == 1) cnt0++;

        ll res =0;
        (res += alithmetic_sum(row0.first, row0.second, cnt0)) %= mod;
        (res += alithmetic_sum(row1.first, row1.second, cnt1)) %= mod;

        cout << res << endl;
    }
} 
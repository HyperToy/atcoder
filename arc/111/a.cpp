#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n % 2) (res *= a) %= mod;
        (a *= a) %= mod;
        n /= 2;
    }
    return res;
}

int main(){
    ll n, m;
    cin >> n >> m;
    cout << modpow(10, n, m * m) / m % m << endl;
}

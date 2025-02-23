#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

ll MOD = 998244353;

long long modpow(long long a, long long n, long long mod) {
    a %= mod;
    long long res = 1;
    while (n > 0) {
        if (n % 2) (res *= a) %= mod;
        (a *= a) %= mod;
        n /= 2;
    }
    return res;
}
long long moddiv(long long x, long long d, long long mod) {
    return (x * modpow(d, mod - 2, mod)) % mod;
}

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    ll sum = 0;
    ll delta = 0;
    rep(i,N) {
        (sum += A[i]) %= MOD;
        // i - 1 番目までの A[i] より大きい要素の和 * 2 を sum に足す
        // i - 1 番目までの A[i] 以下の要素数 * A[i] * 2 を sum に足す
        rep(j,i) (sum += max(A[i], A[j]) * 2) %= MOD;
        ll ans = moddiv(sum, (i + 1) * (i + 1), MOD);
        cout << ans << endl;
    }
}

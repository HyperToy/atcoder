#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

const long long MOD = 1000000000 + 7;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n % 2) (res *= a) %= mod;
        (a *= a) %= mod;
        n /= 2;
    }
    return res;
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    sort(A.begin(), A.end());

    vector<ll> comb(N);
    rep(i,N) {
        if (i < K - 1) comb[i] = 0;
        else if (i == K - 1) comb[i] = 1;
        else comb[i] = comb[i - 1] * i % MOD * modpow(i - K + 1, MOD - 2, MOD) % MOD;
    }

    ll ans = 0;
    rep(i,N) {
        ans += comb[i] * A[i] % MOD;
        ans -= comb[N - i - 1] * A[i] % MOD;
        (ans += MOD) %= MOD;
    }

    cout << ans << endl;
}
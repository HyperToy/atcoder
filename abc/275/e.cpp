#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

ll mod = 998244353;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n % 2) (res *= a) %= mod;
        (a *= a) %= mod;
        n /= 2;
    }
    return res;
}
vector<map<ll, ll>> memo;
long long moddiv(long long x, long long d, long long mod) {
    if (memo[d - 1].count(x)) return memo[d - 1][x];
    return memo[d - 1][x] = (x * modpow(d, mod - 2, mod)) % mod;
}

int main(){
    int N, K;
    ll M;
    cin >> N >> M >> K;

    memo.resize(M);

    vector dp(K + 1, vector<ll>(N + 1, 0));
    dp[0][0] = 1;
    rep(i,K) {
        rep(j,N) {
            for (int d = 1; d <= M; d++) {
                int pos = j + d;
                if (pos > N) pos = N * 2 - pos;
                (dp[i+1][pos] += moddiv(dp[i][j], M, mod)) %= mod;
            }
        }
        (dp[i+1][N] += dp[i][N]) %= mod;
    }
    cout << dp[K][N] << endl;
}

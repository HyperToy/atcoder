#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const ll MOD = 998244353;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        // dp[j][k][l] := j番目までから k個選んで i で割った余りが l である個数
        vector dp(N+1, vector<int>(i, 0));
        dp[0][0] = 1;
        for (int j = 0; j < N; j++) {
            vector nextDp(N+1, vector<int>(i, 0));
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < i; l++) {
                    (nextDp[k][l] += dp[k][l]) %= MOD;
                    (nextDp[k+1][(l + a[j]) % i] += dp[k][l]) %= MOD;
                }
            }
            dp = nextDp;
        }
        (ans += dp[i][0]) %= MOD;
    }

    cout << ans << endl;
} 
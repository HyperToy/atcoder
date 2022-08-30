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

    vector<map<ll, ll>> dp(1);
    dp[0][0] = 1;
    rep(i,N) {
        vector<map<ll, ll>> nextDp(i+2);
        rep(j,i+1) {
            for (auto p : dp[j]) {
                (nextDp[j][p.first] += p.second) %= MOD;
                (nextDp[j+1][p.first + a[i]] += p.second) %= MOD;
            }
        }
        dp = nextDp;
    }

    ll ans = 0;
    for (int j = 1; j <= N; j++) {
        for (auto p : dp[j]) {
            if (p.first % j == 0) {
                (ans += p.second) %= MOD;
            }
        }
    }

    cout << ans << endl;
} 
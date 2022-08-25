#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const ll MOD = 998244353;

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> A(3);
    rep(i,3) cin >> A[i].first >> A[i].second;
    vector<pair<ll, ll>> X(M);
    rep(i,M) cin >> X[i].first >> X[i].second;

    map<pair<ll, ll>, ll> dp;
    dp[{0, 0}] = 1;
    rep(_,N) {
        map<pair<ll, ll>, ll> next_dp;
        for (auto p : dp) {
            ll x = p.first.first;
            ll y = p.first.second;
            rep(i,3) {
                ll nx = x + A[i].first;
                ll ny = y + A[i].second;
                (next_dp[{nx, ny}] += dp[{x, y}]) %= MOD;
            }
        }
        rep(i,M) {
            next_dp.erase({X[i].first, X[i].second});
        }
        dp = next_dp;
    }

    ll ans = 0;
    for (auto p : dp) {
        (ans += p.second) %= MOD;
    }
    cout << ans << endl;
} 
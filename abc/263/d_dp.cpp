#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const long long LINF = 1001001001001001001;
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N;
    ll L, R;
    cin >> N >> L >> R;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<vector<ll>> dp(3, vector<ll>(N, LINF));
    const int l = 0;
    const int a = 1;
    const int r = 2;
    dp[l][0] = L;
    dp[a][0] = A[0];
    dp[r][0] = R;
    rep(i,N-1) {
        chmin(dp[l][i+1], L + dp[l][i]);
        chmin(dp[a][i+1], A[i+1] + min(dp[l][i], dp[a][i]));
        chmin(dp[r][i+1], R + min(dp[l][i], min(dp[a][i], dp[r][i])));
    }

    ll ans = LINF;
    rep(i,3) chmin(ans, dp[i][N-1]);
    cout << ans << endl;
} 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const long long LINF = 1001001001001001001;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}

int main(){
    int N, M;
    cin >> N >> M;
    vector x(N, vector<ll>(3));
    rep(i,N) rep(k,3) cin >> x[i][k];

    vector dp(8, vector(N + 1, vector<ll>(M + 1, -LINF)));
    rep(mask,8) {
        dp[mask][0][0] = 0;
        rep(i,N){
            rep(j,M+1) {
                ll delta = 0;
                rep(k,3) delta += x[i][k] * ((mask >> k) & 1 ? 1 : -1);
                chmax(dp[mask][i + 1][j], dp[mask][i][j]);
                if (j < M) chmax(dp[mask][i + 1][j + 1], dp[mask][i][j] + delta);
            }
        }
    }

    ll ans = -LINF;
    rep(mask,8) chmax(ans, dp[mask][N][M]);
    cout << ans << endl;
}

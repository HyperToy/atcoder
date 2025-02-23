#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    vector<vector<int>> c(M);
    rep(i,M) {
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        rep(j,b[i]) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    vector dp(1 << N, vector<int>(M + 1, INF));
    dp[0][0] = 0;
    rep(i,M) {
        int m = 0;
        rep(j,b[i]) m ^= (1 << c[i][j]);
        rep(S,1 << N) {
            chmin(dp[S][i + 1], dp[S][i]);
            chmin(dp[S | m][i + 1], dp[S][i] + a[i]);
        }
    }

    if (dp[(1 << N) - 1][M] < INF) cout << dp[(1 << N) - 1][M] << endl;
    else cout << -1 << endl;
}

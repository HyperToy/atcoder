#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    rep(i,N) cin >> a[i];

    vector dp(N + 1, vector(M + 1, vector<int>(2, INF)));
    dp[0][0][1] = 0;
    rep(i,N) {
        rep(j,M + 1) {
            chmin(dp[i + 1][j][0], dp[i][j][0]);
            chmin(dp[i + 1][j][0], dp[i][j][1] + 1);
            if (j + a[i] <= M) {
                chmin(dp[i + 1][j + a[i]][1], dp[i][j][0]);
                chmin(dp[i + 1][j + a[i]][1], dp[i][j][1]);
            }
        }
    }
    for (int x = 1; x <= M; x++) {
        int ans = min(dp[N][x][0], dp[N][x][1]);
        if (ans < INF) cout << ans << endl;
        else cout << -1 << endl;
    }
}

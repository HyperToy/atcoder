#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int D, G;
    cin >> D >> G;
    G /= 100;
    int MAX = 0;
    vector<int> p(D), c(D);
    rep(i,D) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
        MAX += (i + 1) * p[i] + c[i];
    }
    MAX++;

    // dp[i][j] := i 問目までの中で j * 100 点以上を取るのに必要な問題数
    vector dp(D+1, vector<int>(MAX, INF));
    dp[0][0] = 0;
    rep(i,D) {
        rep(j,MAX) {
            if (dp[i][j] == INF) break;
            for (int k = 0; k < p[i]; k++) {
                chmin(dp[i + 1][j + k * (i + 1)], dp[i][j] + k);
            }
            chmin(dp[i + 1][j + p[i] * (i + 1) + c[i]], dp[i][j] + p[i]);
        }
        for (int j = MAX - 2; j >= 0; j--) {
            chmin(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    cout << dp[D][G] << endl;

    cerr << "\n// debug ----------------\n";
    rep(j,MAX) {
        cerr << j << ": ";
        rep(i,D+1) {
            if (dp[i][j] < INF) cerr << dp[i][j];
            else cerr << ".";
            cerr << ", ";
        }
        cerr << endl;
    }
}

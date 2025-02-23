#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    rep(i,K) {
        cin >> A[i];
    }

    vector dp(2, vector<int>(N + 1));
    rep(i, N + 1) {
        dp[0][i] = -INF;
        dp[1][i] = INF;
    }
    dp[0][0] = 0;
    dp[1][0] = 0;

    rep(i, N) {
        rep(j,K) {
            if (i + A[j] <= N) {
                chmax(dp[0][i + A[j]], dp[1][i] + A[j]);
                chmin(dp[1][i + A[j]], dp[0][i] - A[j]);
            }
        }
    }

    cout << (N + dp[0][N]) / 2 << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
const long long LINF = 1001001001001001001;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(M), B(M), C(M);
    rep(i,M) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
    }
    vector<int> E(K);
    rep(i,K) {
        cin >> E[i];
        E[i]--;
    }

    vector<ll> dp(N, LINF);
    dp[0] = 0;
    for (int e : E) {
        chmin(dp[B[e]], dp[A[e]] + C[e]);
    }

    if (dp[N - 1] < LINF) cout << dp[N - 1] << endl;
    else cout << -1 << endl;
}
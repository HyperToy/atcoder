#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
const long long LINF = 1001001001001001001;

int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> dp(M+1, -LINF);
    dp[0] = 0;
    rep(i,N) {
        vector<ll> nextDp(M+1, -LINF);
        rep(j,M) {
            chmax(nextDp[j], dp[j]);
            chmax(nextDp[j+1], dp[j] + A[i] * (j+1));
        }
        chmax(nextDp[M], dp[M]);
        dp = nextDp;
    }

    cout << dp[M] << endl;
} 
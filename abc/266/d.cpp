#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const long long LINF = 1001001001001001001;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}

int T_MAX = 100001;

int main(){
    int N;
    cin >> N;
    vector<int> T(N), X(N);
    vector<ll> A(N);
    rep(i,N) cin >> T[i] >> X[i] >> A[i];

    vector<vector<ll>> dp(5, vector<ll>(T_MAX, 0));
    rep(i,N) dp[X[i]][T[i]] = A[i];
    rep(j,5) for (int i = j + 1; i < 5; i++) dp[i][j] = -LINF;

    for (int j = 1; j < T_MAX; j++) {
        rep(i,5) {
            ll now = 0;
            for (int d = -1; d <= 1; d++) {
                if (0 <= i + d && i + d < 5) {
                    chmax(now, dp[i+d][j-1]);
                }
            }
            dp[i][j] += now;
        }
    }

    ll ans = 0;
    rep(i,5) chmax(ans, dp[i][T_MAX-1]);
    cout << ans << endl;
} 
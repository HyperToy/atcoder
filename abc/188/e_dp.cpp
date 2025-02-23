#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const long long LINF = 1001001001001001001;
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<vector<int>> g(N);
    rep(_,M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }

    vector<ll> dp(N, LINF);
    rep(i,N) {
        for (int v : g[i]) {
            chmin(dp[v], min(A[i], dp[i]));
        }
    }

    ll ans = -LINF;
    rep(i,N) chmax(ans, A[i] - dp[i]);
    cout << ans << endl;
} 
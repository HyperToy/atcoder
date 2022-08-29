#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
const long long LINF = 1001001001001001001;

int main(){
    int N;
    cin >> N;
    vector<ll> x(N), y(N), P(N);
    rep(i,N) cin >> x[i] >> y[i] >> P[i];

    vector<vector<ll>> dist(N, vector<ll>(N));
    rep(i,N) rep(j,N) {
        ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        ll S = (d + P[i] - 1) / P[i];
        dist[i][j] = S;
    }

    rep(k,N) rep(i,N) rep(j,N) {
        chmin(dist[i][j], max(dist[i][k], dist[k][j]));
    }

    ll ans = LINF;
    rep(i,N) {
        ll now = 0;
        rep(j,N) chmax(now, dist[i][j]);
        chmin(ans, now);
    }

    cout << ans << endl;
} 
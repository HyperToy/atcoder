#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const long long LINF = 1001001001001001001;
double d(pair<double, double> p, pair<double, double> q) {
    return sqrt((p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second));
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<double, double>> x(N + M + 1);
    x[0].first = x[0].second = 0;
    rep(i,N + M) cin >> x[i + 1].first >> x[i + 1].second;

    vector dist(N + M + 1, vector<double>(N + M + 1, LINF));
    rep(i,N + M + 1) dist[i][i] = 0;
    rep(i,N + M + 1) rep(j,i) {
        dist[i][j] = dist[j][i] = d(x[i], x[j]);
    }

    vector dp(1 << (N + M + 1), vector<double>(N + M + 1, LINF));
    for (int i = 0; i <= M; i++) dp[(1 << N + i + 1) - 1][0] = 0;
    for (int S = (1 << (N + M + 1)) - 1; S >= 0; S--) {
        double speed = 1.0;
        rep(i,M) if (S >> (N + i + 1) & 1) speed *= 2;
        rep(v,N + M + 1) {
            rep(u,N + M + 1) {
                if (!(S >> u & 1)) {
                    dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + dist[v][u] / speed);
                }
            }
        }
    }

    cout << fixed << setprecision(10);
    cout << dp[0][0] << endl;
}

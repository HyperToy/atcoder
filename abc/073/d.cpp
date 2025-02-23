#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

int main(){
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    rep(i,R) cin >> r[i], r[i]--;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    rep(i,N) dist[i][i] = 0;
    rep(_,M) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        dist[A][B] = C;
        dist[B][A] = C;
    }

    rep(k,N) rep(i,N) rep(j,N) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }

    sort(r.begin(), r.end());
    int ans = INF;
    do {
        int now = 0;
        rep(i,R-1) {
            now += dist[r[i]][r[i+1]];
        }
        chmin(ans, now);
    } while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}
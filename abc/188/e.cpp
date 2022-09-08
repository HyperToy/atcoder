#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
const int INF = 1001001001;

int dfs(vector<int> &A, vector<vector<int>> &g, vector<bool> &seen, int mn, int pos, int pre = -1) {
    seen[pos] = true;
    int res = A[pos] - mn;
    for (int nxt : g[pos]) {
        // if (nxt == pre) continue;
        chmax(res, dfs(A, g, seen, min(mn, A[pos]), nxt, pos));
    }
    return res;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<vector<int>> g(N);
    rep(i,N) cin >> A[i];
    rep(_,M) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        g[X].push_back(Y);
    }
    vector<bool> seen(N, false);

    int ans = -INF;
    rep(i,N) {
        if (!seen[i]) {
            chmax(ans, dfs(A, g, seen, INF, i));
        }
    }
    cout << ans << endl;
} 
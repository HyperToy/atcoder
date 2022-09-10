#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
const int INF = 1001001001;
const long long LINF = 1001001001001001001;

ll dfs(vector<ll> &A, vector<vector<int>> &g, vector<bool> &seen, vector<ll> &backmax, int pos, int pre = -1) {
    if (seen[pos]) return backmax[pos];
    seen[pos] = true;
    ll res = -LINF;
    for (int nxt : g[pos]) {
        // if (nxt == pre) continue;
        chmax(res, dfs(A, g, seen, backmax, nxt, pos));
    }
    backmax[pos] = res;
    return max(A[pos], backmax[pos]);
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<vector<int>> g(N);
    rep(i,N) cin >> A[i];
    rep(_,M) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        g[X].push_back(Y);
    }
    vector<bool> seen(N, false);
    vector<ll> backmax(N, -LINF);
    rep(i,N) {
        if (!seen[i]) {
            dfs(A, g, seen, backmax, i);
        }
    }

    ll ans = -LINF;
    rep(i,N) chmax(ans, backmax[i] - A[i]);
    cout << ans << endl;
} 
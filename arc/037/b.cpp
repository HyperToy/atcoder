#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

vector<vector<int>> g;
vector<bool> seen;

int dfs(int pos, int pre = -1) {
    if (seen[pos]) return false;
    seen[pos] = true;

    int res = 1;
    for (int nxt : g[pos]) {
        if (nxt == pre) continue;
        res &= dfs(nxt, pos);
    }
    return res;
}

int main(){
    int N, M;
    cin >> N >> M;
    g.resize(N);
    rep(_,M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    seen.resize(N, false);
    int ans = 0;
    rep(i,N) {
        ans += dfs(i);
    }

    cout << ans << endl;
}
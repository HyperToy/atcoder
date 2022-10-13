#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int N;
vector<vector<int>> g;
vector<int> subtree;
vector<ll> ans;

ll calc_dist_dfs(int u, ll depth, int pre = -1) {
    ll res = depth;
    for (int v : g[u]) {
        if (v == pre) continue;
        res += calc_dist_dfs(v, depth + 1, u);
    }
    return res;
}

int subtree_size_dfs(int u, int pre = -1) {
    int res = 0;
    for (int v : g[u]) {
        if (v == pre) continue;
        res += subtree_size_dfs(v, u);
    }
    return subtree[u] = res + 1;
}

void calc_ans_dfs(int u, ll val, int pre = -1) {
    ans[u] = val - subtree[u] + (N - subtree[u]);
    for (int v : g[u]) {
        if (v == pre) continue;
        calc_ans_dfs(v, ans[u], u);
    }
}

int main(){
    cin >> N;
    g.resize(N);
    rep(_,N-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 頂点0 から各頂点までの距離の和を求める DFS
    ll d = calc_dist_dfs(0, 0);

    // 各頂点の（自身を含む）部分木の超点数を求める DFS
    subtree.resize(N, -1);
    subtree_size_dfs(0);

    // 差分を計算しながら答えを求める DFS
    ans.resize(N, -1);
    calc_ans_dfs(0, d + N);

    for (ll x : ans) cout << x << endl;
}

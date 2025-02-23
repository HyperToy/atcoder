#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

constexpr int INF = 1001001001;


void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    rep(i,N) cin >> C[i];
    vector<vector<int>> g(N);
    rep(i,M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (C[0] == C[N - 1]) {
        cout << -1 << endl;
        return;
    }

    vector<vector<int>> dist(N, vector<int>(N, INF)); // {i, j} -> 高橋くんがi, 青木くんがj にいるまでの最短
    queue<pair<int, int>> q;
    dist[0][N - 1] = 0;
    q.emplace(0, N - 1);
    while (!q.empty()) {
        int takahashi = q.front().first;
        int aoki = q.front().second;
        q.pop();
        for (int next_takahashi : g[takahashi]) {
            for (int next_aoki : g[aoki]) {
                if (C[next_takahashi] == C[next_aoki]) continue;
                if (dist[next_takahashi][next_aoki] <= dist[takahashi][aoki] + 1) continue;
                dist[next_takahashi][next_aoki] = dist[takahashi][aoki] + 1;
                q.emplace(next_takahashi, next_aoki);
            }
        }
    }

    if (dist[N - 1][0] < INF) cout << dist[N - 1][0] << endl;
    else cout << -1 << endl;
}

int main(){
    int T;
    cin >> T;
    rep(_,T) solve();
}

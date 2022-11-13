#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int INF = 1001001001;
struct edge{int to, cost; };

void dijkstra(vector<int> &dist, vector<vector<edge>> &g, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {最小コスト, 頂点}
    fill(dist.begin(), dist.end(), INF);

    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        pair<int, int> p = pq.top(); pq.pop();
        int u = p.second;
        
        if (dist[u] < p.first) continue;

        for (edge &e : g[u]) {
            int v = e.to;
            if (dist[v] > dist[u] + e.cost) {
                dist[v] = dist[u] + e.cost;
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<edge>> g(N * 2);
    rep(_,M) {
        int u, v, a;
        cin >> u >> v >> a;
        u--; v--;
        if (a == 1) {
            g[u].push_back(edge{v, 1});
            g[v].push_back(edge{u, 1});
        } else {
            g[u + N].push_back(edge{v + N, 1});
            g[v + N].push_back(edge{u + N, 1});
        }
    }
    rep(_,K) {
        int s;
        cin >> s;
        s--;
        g[s].push_back(edge{s + N, 0});
        g[s + N].push_back(edge{s, 0});
    }

    vector<int> dist(N * 2);
    dijkstra(dist, g, 0);

    int ans = min(dist[N - 1], dist[2 * N - 1]);
    if (ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}

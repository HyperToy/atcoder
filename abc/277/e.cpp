// TODO: refactor
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int INF = 1001001001;
struct edge{int to, cost; bool avarable; };

void dijkstra(
    vector<int> &dist, 
    vector<vector<edge>> &g, 
    vector<int> &rdist, 
    vector<vector<edge>> &rg, 
    vector<bool> &sw,
    int s
) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // {最小コスト, 頂点}
    fill(dist.begin(), dist.end(), INF);

    dist[s] = 0;
    pq.push({dist[s], {s, 1}});

    while (!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top(); pq.pop();
        int v = p.second.first;
        int a = p.second.second;
        
        if (a == 1) {
            if (dist[v] < p.first) continue;

            for (edge &e : g[v]) {
                if (!e.avarable) continue;
                if (dist[e.to] > dist[v] + e.cost) {
                    dist[e.to] = dist[v] + e.cost;
                    pq.push({dist[e.to], {e.to, a}});
                }
            }
            if (sw[v] && rdist[v] > dist[v]) {
                rdist[v] = dist[v];
                pq.push({rdist[v], {v, 1 - a}});
            }
        } else {
            if (rdist[v] < p.first) continue;

            for (edge &e : rg[v]) {
                if (!e.avarable) continue;
                if (rdist[e.to] > rdist[v] + e.cost) {
                    rdist[e.to] = rdist[v] + e.cost;
                    pq.push({rdist[e.to], {e.to, a}});
                }
            }
            if (sw[v] && dist[v] > rdist[v]) {
                dist[v] = rdist[v];
                pq.push({dist[v], {v, 1 - a}});
            }
        }
    }
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<edge>> g(N);
    vector<vector<edge>> rg(N);
    vector<bool> sw(N, false);
    rep(i,M) {
        int u, v, a;
        cin >> u >> v >> a;
        u--; v--;
        g[u].push_back(edge{v, 1, a == 1});
        g[v].push_back(edge{u, 1, a == 1});
        rg[u].push_back(edge{v, 1, a == 0});
        rg[v].push_back(edge{u, 1, a == 0});
    }
    rep(_,K) {
        int s;
        cin >> s;
        s--;
        sw[s] = true;
    }

    vector<int> dist(N, INF);
    vector<int> rdist(N, INF);
    dijkstra(dist, g, rdist, rg, sw, 0);

    int ans = min(dist[N - 1], rdist[N - 1]);
    if (ans < INF) cout << ans << endl;
    else cout << -1 << endl;
}

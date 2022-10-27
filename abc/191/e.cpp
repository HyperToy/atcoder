#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
const int INF = 1001001001;

struct edge{int to, cost; };

void dijkstra(vector<int> &dist, vector<vector<edge>> &g, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {最小コスト, 頂点}
    fill(dist.begin(), dist.end(), INF);

    dist[s] = 0;
    pq.push({dist[s], s});

    while (!pq.empty()) {
        pair<int, int> p = pq.top(); pq.pop();
        int v = p.second;
        
        if (dist[v] < p.first) continue;

        for (edge &e : g[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<edge>> g(N);
    vector<vector<edge>> rg(N);
    rep(_,M) {
        int v, u, w;
        cin >> v >> u >> w;
        v--; u--;
        g[v].push_back(edge{u, w});
        rg[u].push_back(edge{v, w});
    }
    rep(i,N) {
        vector<int> dist(N);
        vector<int> rdist(N);
        dijkstra(dist, g, i);
        dijkstra(rdist, rg, i);

        int ans = INF;
        for (edge &e : g[i]) {
            if (e.to == i) chmin(ans, e.cost); 
        }
        rep(j,N) {
            if (j == i) continue;
            chmin(ans, dist[j] + rdist[j]);
        }
        if (ans < INF) cout << ans << endl;
        else cout << -1 << endl;
    }
} 
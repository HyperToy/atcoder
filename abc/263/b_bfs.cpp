#include <bits/stdc++.h>
using namespace std;
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 1; i < N; i++) cin >> P[i], P[i]--;

    vector<vector<int>> g(N);
    for (int i = 1; i < N; i++) {
        g[P[i]].push_back(i);
    }

    queue<int> q;
    vector<int> dist(N, INF);
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] < INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    cout << dist[N-1] << endl;
} 
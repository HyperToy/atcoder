#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const long long LINF = 1001001001001001001;

int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<vector<int>> g(N);
    vector<ll> cost(N, 0);
    rep(_,M) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        g[U].push_back(V);
        g[V].push_back(U);
        cost[U] += A[V];
        cost[V] += A[U];
    }

    priority_queue<pair<ll, int>> q;
    rep(i,N) q.emplace(-cost[i], i);
    vector<bool> erased(N, false);
    ll ans = 0;
    while (!q.empty()) {
        ll c = -q.top().first;
        int u = q.top().second;
        q.pop();
        if (erased[u]) continue;
        erased[u] = true;
        ans = max(ans, c);
        for (int v : g[u]) {
            cost[v] -= A[u];
            q.emplace(-cost[v], v);
        }
    }

    cout << ans << endl;
}
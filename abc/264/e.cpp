#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

struct UnionFind {
private:
    vector<int> par;
public:
    UnionFind(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
        sts.resize(n);
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x > y) swap(x, y);
        if (x == y) return;
        par[x] = y;
    }
    int root(int x) {
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    }
};

int main(){
    int N, M, E;
    cin >> N >> M >> E;
    vector<int> U(E), V(E);
    rep(i,E) {
        cin >> U[i] >> V[i];
        U[i]--; V[i]--;
    }
    int Q;
    cin >> Q;
    vector<int> X(Q);
    vector<bool> connected(E, true);
    rep(i,Q) {
        cin >> X[i];
        X[i]--;
        connected[X[i]] = false;
    }

    vector<vector<int>> g(N + M);
    UnionFind uf = UnionFind(N + M);
    rep(i,E) {
        if (connected[i]) {
            uf.unite(U[i], V[i]);
            g[U[i]].push_back(V[i]);
            g[V[i]].push_back(U[i]);
        }
    }

    set<int> now_on_cities;
    rep(i,N) if (uf.root(i) >= N) {
        now_on_cities.insert(i);
    }

    vector<int> ans(Q);
    reverse(X.begin(), X.end());
    rep(i,Q) {
        ans[i] = now_on_cities.size();
        int u = U[X[i]];
        int v = V[X[i]];
        uf.unite(u, v);
        if (u < N && now_on_cities.count(u) == 0){
            if (uf.root(u) >= N) {
                now_on_cities.insert(u);
                queue<int> q;
                q.push(u);
                while (!q.empty()) {
                    int a = q.front(); q.pop();
                    for (int b : g[a]) {
                        if (now_on_cities.count(b) > 0) continue;
                        now_on_cities.insert(b);
                        q.push(b);
                    }
                }
            }
            g[u].push_back(v);
        } 
        if (v < N && now_on_cities.count(v) == 0) {
            if (uf.root(v) >= N) {
                now_on_cities.insert(v);
                queue<int> q;
                q.push(v);
                while (!q.empty()) {
                    int a = q.front(); q.pop();
                    for (int b : g[a]) {
                        if (now_on_cities.count(b) > 0) continue;
                        now_on_cities.insert(b);
                        q.push(b);
                    }
                }
            }
            g[v].push_back(u);
        }
    }

    reverse(ans.begin(), ans.end());
    rep(i,Q) cout << ans[i] << endl;
}

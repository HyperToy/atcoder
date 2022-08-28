#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

struct UnionFind {
private:
    vector<int> par;
public:
    UnionFind(int n) {
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        par[x] = y;
    }
private:
    int root(int x) {
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    }
};

struct edge {int u, v; ll w; };
bool comp(edge &s, edge &t) {return s.w < t.w; }

int main(){
    int N;
    cin >> N;
    vector<ll> x(N), y(N), P(N);
    rep(i,N) cin >> x[i] >> y[i] >> P[i];

    vector<edge> es;
    rep(i,N) rep(j,N) {
        if (i == j) continue;
        ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        ll S = (d + P[i] - 1) / P[i];
        es.push_back(edge{i, j, S});
    }

    sort(es.begin(), es.end(), comp);

    UnionFind uf = UnionFind(N);
    ll ans = 0;
    for (edge &e : es) {
        if (uf.same(e.u, e.v)) continue;
        uf.unite(e.u, e.v);
        ans = e.w;
    }

    cout << ans << endl;
} 
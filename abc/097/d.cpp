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

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> p(N);
    rep(i,N) cin >> p[i], p[i]--;
    UnionFind uf = UnionFind(N);
    rep(i,M) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        uf.unite(x, y);
    }

    int ans = 0;
    rep(i,N) {
        if (uf.same(p[i], i)) ans++;
    }
    cout << ans << endl;
} 
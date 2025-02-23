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
    int count_roots() {
        set<int> st;
        rep(i,par.size()) st.insert(root(i));
        return st.size();
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

    UnionFind uf = UnionFind(N);
    rep(_,M) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        X--, Y--;
        if (!uf.same(X, Y)) uf.unite(X, Y);
    }

    cout << uf.count_roots() << endl;
}
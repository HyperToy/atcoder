#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

// コピペ　----------------------------------------------------------------
// cf. https://algo-logic.info/bipartite-matching/
template <class T>
struct Edge {
    int rev, from, to;  // rev:逆向きの辺の番号
    T cap, original_cap;
    Edge(int r, int f, int t, T c) : rev(r), from(f), to(t), cap(c), original_cap(c) {}
};
template <class T>
struct Graph {
    vector<vector<Edge<T>>> G;
    Graph(int n = 0) : G(n) {}
    vector<Edge<T>>& operator[](int i) { return G[i]; }
    const size_t size() const { return G.size(); }
    Edge<T>& redge(Edge<T> e) {  // 逆向きの辺を返す
        return G[e.to][e.rev];   // 自己ループはないと仮定（あれば G[e.to][e.rev + 1] とする必要がある）
    }
    void add_edge(int from, int to, T cap) {  // 有向辺を加える
        G[from].push_back(Edge<T>((int)G[to].size(), from, to, cap));
        G[to].push_back(Edge<T>((int)G[from].size() - 1, to, from, 0));
    }
};
/* FordFulkerson: Ford-Fulkersonのアルゴリズムで最大流を求める構造体
    max_flow(G,s,t) ：グラフGの最大流が求まる
    副作用：G は最大流の残余ネットワークになる
    計算量: O(|f*||E|) (f*:最大流) 
*/
template <class T>
struct FordFulkerson {
    const T INF = 1e9;
    vector<int> used;
    FordFulkerson(){};
    T dfs(Graph<T>& G, int v, int t, T f) {  // 増加可能経路を見つけて増加分のフローを返す
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                T d = dfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G.redge(e).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(Graph<T>& G, int s, int t) {
        T flow = 0;
        while (true) {
            used.assign(G.size(), 0);
            T f = dfs(G, s, t, INF);  // f が増加分のフロー
            if (f == 0) {
                return flow;
            } else {
                flow += f;
            }
        }
        return 0;
    }
};
// ----------------------------------------------------------------

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> r(N), b(N);
    for (auto &p : r) cin >> p.first >> p.second;
    for (auto &p : b) cin >> p.first >> p.second;

    // 二部グラフの最大マッチングを求める問題に帰着できる。
    // 最大流アルゴリズムを使える。
    // 制約的に、多分オーバーキル。

    Graph<int> G(N * 2 + 2);
    rep(i,N) {
        G.add_edge(0, i + 1, 1);
    }
    rep(i,N) rep(j,N) {
        if (r[i].first < b[j].first && r[i].second < b[j].second) {
            G.add_edge(i + 1, j + N + 1, 1);
        }
    }
    rep(i,N) {
        G.add_edge(i + N + 1, N * 2 + 1, 1);
    }

    FordFulkerson<int> ff;
    cout << ff.max_flow(G, 0, N * 2 + 1) << endl;
}
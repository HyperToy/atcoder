#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

struct edge {int to; ll cost; };

bool check(vector<vector<edge>> &g, ll S) {
    int N = g.size();
    rep(i,N) {
        set<int> seen;
        queue<int> q;
        seen.insert(i);
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (edge e : g[u]) {
                if (e.cost > S) continue;
                int v = e.to;
                if (seen.count(v)) continue;
                seen.insert(v);
                q.push(v);
            }
        }
        if (seen.size() == N) {
            return true;
        }
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<ll> x(N), y(N), P(N);
    rep(i,N) cin >> x[i] >> y[i] >> P[i];

    vector<vector<edge>> g(N);
    rep(i,N) rep(j,N) {
        if (i == j) continue;
        ll d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        ll S = (d + P[i] - 1) / P[i];
        g[i].push_back(edge{j, S});
    }

    ll wa = 0;
    ll ac = 4000000000LL;
    while (wa + 1 < ac) {
        ll wj = (wa + ac) / 2;
        if (check(g, wj)) ac = wj;
        else wa = wj;
    }

    cout << ac << endl;
} 
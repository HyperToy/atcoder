#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int INF = 1001001001;

int main(){
    int N, X, Y;
    cin >> N >> X >> Y;
    X--; Y--;
    vector<vector<int>> g(N);
    rep(i,N-1) {
        int U, V;
        cin >> U >> V;
        U--; V--;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    vector<int> dist(N, INF);
    queue<int> q;
    dist[X] = 0;
    q.push(X);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] < dist[u] + 1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    stack<int> ans;
    ans.push(Y);
    while (1) {
        int u = ans.top();
        for (int v : g[u]) {
            if (dist[v] == dist[u] - 1) {
                ans.push(v);
                break;
            }
        }
        if (ans.top() == X) break;
    }

    while (!ans.empty()) {
        cout << ans.top() + 1 << endl;
        ans.pop();
    }
}
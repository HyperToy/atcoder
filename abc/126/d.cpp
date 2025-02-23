#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> to(n);
    rep(i,n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        to[u].push_back({v,w});
        to[v].push_back({u,w});
    }
    vector<int> ans(n, -1);
    queue<int> q;

    ans[0] = 0;
    q.push(0);
    while (q.size()) {
        int v = q.front(); q.pop();
        for (auto p : to[v]) {
            int u = p.first;
            int w = p.second;
            if (ans[u] != -1) continue;

            if ((w%2) == ans[v]) ans[u] = 0;
            else ans[u] = 1;
            q.push(u);
        }
    }
    
    rep(i,n) cout << ans[i] << endl;
} 
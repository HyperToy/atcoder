#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    map<int, set<int>> g;
    rep(i,N) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    set<int> reachable;
    queue<int> q;
    reachable.insert(1);
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (reachable.count(v)) continue;
            reachable.insert(v);
            q.push(v);
        }
    }

    int ans = 1;
    for (int x : reachable) {
        ans = max(ans, x);
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, MAX = 400000;
    cin >> N;
    vector<vector<int>> g(MAX);
    rep(_,N) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector seen(MAX, false);
    queue<int> q;
    int ans = 0;
    rep(i,MAX) {
        if (seen[i]) continue;
        seen[i] = true;
        q.push(i);
        bool isTree = true;
        int size = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            size++;
            int cnt = 0;
            for (int v : g[u]) {
                if (seen[v]) {
                    cnt++;
                    continue;
                }
                seen[v] = true;
                q.push(v);
            }
            if (cnt > 1) isTree = false;
        }
        if (isTree) ans += size - 1;
        else ans += size;
    }
    cout << ans << endl;
}

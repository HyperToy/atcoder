#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N, M;
    cin >> N >> M;
    vector<set<int>> g(N);
    rep(i,M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].insert(b);
        g[b].insert(a);
    }

    rep(u,N) {
        cout << g[u].size() << " ";
        for (int v : g[u]) {
            cout << v + 1 << " ";
        }
        cout << endl;
    }
}

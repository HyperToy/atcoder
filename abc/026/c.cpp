#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int dfs(int u, vector<vector<int>> g) {
    if (g[u].size() == 0) return 1;
    int mx = 0;
    int mn = INF;
    for (int v : g[u]) {
        int now = dfs(v, g);
        mx = max(mx, now);
        mn = min(mn, now);
    }
    return mx + mn + 1;
}

int main(){
    int N;
    cin >> N;
    vector<int> B(N);
    for (int i = 1; i < N; i++) {
        cin >> B[i];
        B[i]--;
    }

    // 上司 → 部下 の有向グラフ
    vector<vector<int>> g(N);
    for (int i = 1; i < N; i++) {
        g[B[i]].push_back(i);
    }

    cout << dfs(0, g) << endl;
}
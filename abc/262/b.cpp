#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N, vector<int>(N, 0));
    rep(_,M) {
        int U, V;
        cin >> U >> V;
        --U; --V;
        g[U][V] = 1;
    }

    int ans = 0;
    rep(k,N) rep(j,k) rep(i,j) {
        if (!g[i][j]) continue;
        if (!g[j][k]) continue;
        if (!g[i][k]) continue;
        ans++;
    }

    cout << ans << endl;
}

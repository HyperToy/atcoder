#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 1001001001;
bool inside(int h, int w, int H, int W) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> dir;
    rep(l,N+1) rep(k,l+1) {
        if (l * l + k * k == M) {
            rep(_,2) {
                dir.emplace_back(k, l);
                dir.emplace_back(-k, l);
                dir.emplace_back(k, -l);
                dir.emplace_back(-k, -l);
                swap(k,l);
            }
        }
    }

    vector dist(N, vector<int>(N, INF));
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (auto p : dir) {
            int nx = x + p.first;
            int ny = y + p.second;
            if (!inside(nx, ny, N, N)) continue;
            if (dist[nx][ny] < INF) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
        }
    }

    rep(i,N) rep(j,N) {
        if (dist[i][j] < INF) cout << dist[i][j];
        else cout << -1 << endl;
        if (j == N-1) cout << endl;
        else cout << " ";
    }
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

constexpr int INF = 1001001001;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};

int main(){
    // input 
    int h, w;
    cin >> h >> w;
    vector<vector<char>> f(h+2, vector<char>(w+2, '#'));
    for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) cin >> f[i][j];

    // bfs
    int ans = 0;
    for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) {
        if (f[i][j] == '#') continue;
        vector<vector<int>> a(h+2, vector<int>(w+2, INF));
        queue<pair<int, int>> q;
        a[i][j] = 0;
        q.emplace(i, j);
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            rep(k,4) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (f[nx][ny] == '#') continue;
                if (a[nx][ny] < INF) continue;
                a[nx][ny] = a[x][y] + 1;
                ans = max(ans, a[nx][ny]);
                q.emplace(nx, ny);
            }
        }
    }

    // output
    cout << ans << endl;
} 
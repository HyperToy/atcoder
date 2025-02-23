#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl
const int dx[] = {1, 1, 0, -1, -1, 0};
const int dy[] = {0, 1, 1, 0, -1, -1};
int L = 3000;
vector<vector<bool>> seen;
vector<vector<int>> field;

bool inside(int h, int w, int H, int W) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

void dfs(int x, int y, int px = -1, int py = -1) {
    seen[x][y] = true;
    
    rep(k,6) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!inside(nx, ny, L, L)) continue;
        if (seen[nx][ny]) continue;
        if (field[nx][ny] != 1) continue;
        dfs(nx, ny, x, y);
    }
}

int main(){
    seen = vector(L, vector<bool>(L, false));
    field = vector(L, vector<int>(L, 0));

    int N;
    cin >> N;
    rep(i,N) {
        int X, Y;
        cin >> X >> Y;
        X += L / 2;
        Y += L / 2;
        field[X][Y] = 1;
    }

    int ans = 0;
    rep(i,L) rep(j,L) {
        if (field[i][j] != 1) continue;
        if (seen[i][j]) continue;
        ans++;
        dfs(i,j);
    }

    cout << ans << endl;
} 
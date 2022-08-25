#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const string ds = "DRUL";

bool inside(int h, int w, int H, int W) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> G(H);
    rep(i,H) cin >> G[i];

    vector<vector<int>> seen(H, vector<int>(W, false));
    int x = 0, y = 0;
    seen[x][y] = true;

    while (true) {
        int k = 0;
        while (ds[k] != G[x][y]) k++;
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!inside(nx, ny, H, W)) {
            cout << x + 1 << " " << y + 1 << endl;
            return 0;
        } 
        if (seen[nx][ny]) {
            cout << -1 << endl;
            return 0;
        }
        seen[nx][ny] = true;
        x = nx;
        y = ny;
    }
} 
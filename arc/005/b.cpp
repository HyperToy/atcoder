#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
// #define PR(x) cerr << #x << " = " << x << endl

const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ds[] = {"D", "RD", "R", "RU", "U", "LU", "L", "LD"};
bool inside(int h, int w, int H = 9, int W = 9) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

int main(){
    int x, y;
    string W;
    cin >> x >> y >> W;
    x--; y--;
    vector<string> c(9);
    rep(i,9) cin >> c[i];

    rep(k,8) {
        if (ds[k] != W) continue;
        string ans;
        int vx = dx[k];
        int vy = dy[k];
        rep(_,4) {
            ans += c[y][x];
            if (!inside(x, y + vy)) vy *= -1;
            if (!inside(x + vx, y)) vx *= -1;
            x += vx;
            y += vy;
        }
        cout << ans << endl;
        return 0;
    }
}
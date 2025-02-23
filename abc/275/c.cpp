#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

bool inside(int h, int w, int H, int W) {
    return 0 <= h && h < H && 0 <= w && w < W;
}
struct point {int x, y; };

int main(){
    int n = 9;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int ans = 0;
    vector<point> ps(4);
    rep(i,n*n) {
        ps[0].x = i / n;
        ps[0].y = i % n;
        rep(j,n*n) {
            if (i == j) continue;

            ps[1].x = j / n;
            ps[1].y = j % n;

            ps[2].x = ps[0].x + ps[0].y - ps[1].y;
            ps[2].y = ps[0].y + ps[1].x - ps[0].x;
            if (!inside(ps[2].x, ps[2].y, n, n)) continue;

            ps[3].x = ps[2].x + ps[1].x - ps[0].x;
            ps[3].y = ps[2].y + ps[1].y - ps[0].y;
            if (!inside(ps[3].x, ps[3].y, n, n)) continue;

            bool ok = true;
            rep(k,4) if (s[ps[k].x][ps[k].y] != '#') ok = false;
            if (ok) ans++;
        }
    }
    cout << ans / 4 << endl;
}

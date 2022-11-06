#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int H, W;
bool inside(int h, int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

P start;
set<P> walls;
set<P> seen;
string ans;
void dfs(P pos, P pre = {-1, -1}) {
    if (ans == "Yes") return;
    if (seen.count(pos)) return;
    seen.insert(pos);

    rep(dir,4) {
        P nxt = {pos.first + dx[dir], pos.second + dy[dir]};
        if (!inside(nxt.first, nxt.second)) continue;
        if (walls.count(nxt)) continue;
        if (nxt == pre) continue;

        if (nxt == start) ans = "Yes";
        dfs(nxt, pos);
    }
}

int main(){
    cin >> H >> W;
    rep(i,H) {
        string S;
        cin >> S;
        rep(j,W) {
            if (S[j] == 'S') {
                start.first = i;
                start.second = j;
            } else if (S[j] == '#') {
                walls.insert({i, j});
            }
        }
    }
    ans = "No";
    dfs(start);

    cout << ans << endl;
}

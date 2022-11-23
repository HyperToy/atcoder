#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

bool inside(int h, int w, int H, int W) {
    return 0 <= h && h < H && 0 <= w && w < W;
}

int main(){
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector A(H, vector<int>(W));
    rep(i,H) rep(j,W) {
        cin >> A[i][j];
        A[i][j]--;
    }

    vector<vector<vector<int>>> sum(H, vector<vector<int>>(W, vector<int>(N, 0)));
    rep(i,H) rep(j,W) {
        sum[i][j][A[i][j]]++;
        rep(x,N) {
            if (i > 0) sum[i][j][x] += sum[i - 1][j][x];
            if (j > 0) sum[i][j][x] += sum[i][j - 1][x];
            if (i * j > 0) sum[i][j][x] -= sum[i - 1][j - 1][x];
        }
    }
    rep(k, H - h + 1) rep(l, W - w + 1) {
        int ans = 0;
        rep(x,N) {
            int cnt = sum[H - 1][W - 1][x];
            cnt -= sum[k + h - 1][l + w - 1][x];
            if (k > 0) cnt += sum[k - 1][l + w - 1][x];
            if (l > 0) cnt += sum[k + h - 1][l - 1][x];
            if (k * l > 0) cnt -= sum[k - 1][l - 1][x];
            if (cnt > 0) ans++;
        }
        cout << ans;
        if (l == W - w) cout << endl;
        else cout << " ";
    }
    // TLE:
    // vector<vector<vector<int>>> memo(H - h + 1, vector<vector<int>>(W - w + 1, vector<int>(N, 0)));
    // rep(i,H) rep(j,W) {
    //     if (!inside(i, j, h, w)) {
    //         memo[0][0][A[i][j]]++;
    //     }
    // }
    // rep(k, H - h + 1) rep(l, W - w + 1) {
    //     if (k > 0 && l == 0) {
    //         // 上からの差分
    //         memo[k][l] = memo[k - 1][l];
    //         // [k - 1][l..l + w] を復活させる
    //         rep(j,w) memo[k][l][A[k - 1][l + j]]++;
    //         // [k + h - 1][l..l + w] を消す
    //         rep(j,w) memo[k][l][A[k + h - 1][l + j]]--;
    //     } else if (l > 0) {
    //         // 左からの差分
    //         memo[k][l] = memo[k][l - 1];
    //         // [k..k + h][l - 1] を復活させる
    //         rep(i,h) memo[k][l][A[k + i][l - 1]]++;
    //         // [k..k + h][l + w - 1] を消す
    //         rep(i,h) memo[k][l][A[k + i][l + w - 1]]--;
    //     } else {
    //         // 前計算済み
    //     }
    //     int ans = 0;
    //     for (auto p : memo[k][l]) {
    //         if (p > 0) ans++;
    //     }
    //     cout << ans;
    //     if (l == W - w) cout << endl;
    //     else cout << " ";
    // }
}

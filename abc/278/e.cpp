#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector A(H, vector<int>(W));
    rep(i,H) rep(j,W) {
        cin >> A[i][j];
        A[i][j]--;
    }

    vector<vector<vector<int>>> sum(N, vector<vector<int>>(H, vector<int>(W, 0)));
    rep(i,H) rep(j,W) {
        sum[A[i][j]][i][j]++;
        rep(x,N) {
            if (i > 0) sum[x][i][j] += sum[x][i - 1][j];
            if (j > 0) sum[x][i][j] += sum[x][i][j - 1];
            if (i * j > 0) sum[x][i][j] -= sum[x][i - 1][j - 1];
        }
    }
    rep(k, H - h + 1) rep(l, W - w + 1) {
        int ans = 0;
        rep(x,N) {
            int cnt = sum[x][H - 1][W - 1];
            cnt -= sum[x][k + h - 1][l + w - 1];
            if (k > 0) cnt += sum[x][k - 1][l + w - 1];
            if (l > 0) cnt += sum[x][k + h - 1][l - 1];
            if (k * l > 0) cnt -= sum[x][k - 1][l - 1];
            if (cnt > 0) ans++;
        }
        cout << ans;
        if (l == W - w) cout << endl;
        else cout << " ";
    }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int H, W;
    cin >> H >> W;
    vector X(H, vector<int>(W));
    rep(i,H) rep(j,W) cin >> X[i][j];

    vector S(H + 1, vector<int>(W + 1, 0));
    rep(i,H) rep(j,W) {
        S[i + 1][j + 1] = S[i + 1][j] + S[i][j + 1] - S[i][j];
        S[i + 1][j + 1] += X[i][j];
    }

    int Q;
    cin >> Q;
    rep(_,Q) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        A--; B--;
        int ans = S[C][D] - S[A][D] - S[C][B] + S[A][B];
        cout << ans << endl;
    }
}

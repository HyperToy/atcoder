#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector S(H + 1, vector<int>(W + 1, 0));
    rep(_,N) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        A--; B--;
        S[A][B]++;
        S[C][B]--;
        S[A][D]--;
        S[C][D]++;
    }

    rep(i,H) rep(j,W) {
        S[i][j + 1] += S[i][j];
    }
    rep(j,W) rep(i,H) {
        S[i + 1][j] += S[i][j];
    }

    rep(i,H) rep(j,W) {
        cout << S[i][j];
        if (j == W - 1) cout << endl;
        else cout << " ";
    }
}

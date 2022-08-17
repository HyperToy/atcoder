#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int H1, W1;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    rep(i,H1) rep(j,W1) cin >> A[i][j];
    int H2, W2;
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    rep(i,H2) rep(j,W2) cin >> B[i][j];

    bool ok = false;
    rep(r,(1<<H1)) {
        if (__builtin_popcount(r) != H2) continue;
        rep(c,(1<<W1)) {
            if (__builtin_popcount(c) != W2) continue;
            int i2 = 0;
            bool found = true;
            rep(i1, H1) {
                if (!((r>>i1) & 1)) continue;
                int j2 = 0;
                rep(j1,W1) {
                    if (!((c>>j1) & 1)) continue;
                    if (A[i1][j1] != B[i2][j2]) {
                        found = false;
                    }
                    j2++;
                }
                i2++;
            }
            if (found) ok = true;
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

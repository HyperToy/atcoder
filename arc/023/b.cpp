#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PR(x) cerr << #x << " = " << x << endl

int main(){
    int R, C, D;
    cin >> R >> C >> D;
    vector<vector<int>> A(R, vector<int>(C));
    rep(i,R) rep(j,C) cin >> A[i][j];

    int ans = -1;
    rep(i,R) rep(j,C) {
        if ((i + j) <= D && (D - i - j) % 2 == 0) {
            ans = max(ans, A[i][j]);
        }
    }

    cout << ans << endl;
}
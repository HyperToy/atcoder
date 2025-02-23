#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    int MAX = 2000;
    vector S(MAX + 1, vector<int>(MAX + 1, 0));
    rep(i,N) {
        int X, Y;
        cin >> X >> Y;
        S[X][Y]++;
    }
    rep(i,MAX) rep(j,MAX) {
        S[i + 1][j + 1] += S[i][j + 1] + S[i + 1][j] - S[i][j];
    }

    int Q;
    cin >> Q;
    rep(_,Q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        int ans = S[c][d] - S[a][d] - S[c][b] + S[a][b];
        cout << ans << endl;
    }
}

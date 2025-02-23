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
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        // A--; B--;
        S[A][B]++;
        S[C][B]--;
        S[A][D]--;
        S[C][D]++;
    }
    rep(i,MAX) rep(j,MAX) {
        S[i][j + 1] += S[i][j];
    }
    rep(j,MAX) rep(i,MAX) {
        S[i + 1][j] += S[i][j];
    }

    int ans = 0;
    rep(i,MAX) rep(j,MAX) {
        if (S[i][j] > 0) ans++;
    }
    cout << ans << endl;
}

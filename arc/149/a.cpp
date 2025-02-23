#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N, M;
    cin >> N >> M;

    // dp[i][j] := j を i 個並べた数字を M で割ったあまり
    vector dp(N + 1, vector<ll>(10, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i - 1][j] * 10 + j) % M;
        }
    }

    for (int i = N; i > 0; i--) {
        for (int j = 9; j > 0; j--) {
            if (dp[i][j] == 0) {
                string ans = string(i, '0' + j);
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}